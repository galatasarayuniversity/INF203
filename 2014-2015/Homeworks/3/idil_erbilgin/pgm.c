#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "pgm.h"

/* PGM dosyasinin baslik bilgilerini ekrana yazdiran fonksiyon */
void pgm_print_header(PGMInfo pgm_info)
{
	printf("This is a %s type PGM image containing %d x %d pixels\n", pgm_info.signature, pgm_info.width, pgm_info.height);
}

PGMInfo pgm_read(const char *filename)
{
	/* Bu fonksiyon filename stringi ile verilen dosyayi fopen()
	 * ile read kipinde acmali ve PGM dosyasinin basligini ve
	 * piksellerini PGMInfo turunden bir struct'a atmalidir.
	 *
	 * Fonksiyon geriye bu struct'i dondurmelidir.
	 */

	/* PGMInfo turunden bir degisken yaratip, error uyesini 0 yaptik. */
	PGMInfo pgm_info = {.error = 0 };

	/* Dosyadaki satirlari okumak icin bir tampon. */
	char line[LINE_MAX];
	char buffer[LINE_MAX];
	char layn[LINE_MAX];
	int i = 0;
	int j;
	int read = 0;

	/* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
	 * uyesini PGM_ERROR_READ yapip fonksiyonu return ettirin. XX*/
	FILE *pgm = fopen(filename, "r");

	if (pgm == NULL) {
		pgm_info.error = PGM_ERROR_READ;
	}

	/* Dosyadan tam bir satiri line tamponuna okuyalim. */
	fgets(line, sizeof(line), pgm);
	/* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim. */
	sscanf(line, "%s", pgm_info.signature);

	/* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
	 * PGM_ERROR_SIGNATURE yapip fonksiyonu return ettirin.pgm_info.signature ı kontrol et p2 mi p5 mi. XX
	 */
	if (pgm_info.signature[1] != '2' && pgm_info.signature[1] != '5' && pgm_info.signature[0] != 'P') {
		fclose(pgm);
		pgm_info.error = PGM_ERROR_SIGNATURE;
	}

	/* Comment satirini oku. */
	fgets(pgm_info.comment, sizeof(line), pgm);

	/* TODO: En ve boyu oku XX */
	fgets(line, sizeof(line), pgm);

	while (line[i] != ' ') {

		buffer[i] = line[i];
		++i;
	}

	pgm_info.width = atoi(buffer);

	while (line[i] != '\n') {

		buffer[j] = line[i];
		++j;
		++i;
	}

	pgm_info.height = atoi(buffer);
	i = 0;

	/* TODO: Max piksel degerini oku XX */
	fgets(line, sizeof(line), pgm);
	pgm_info.max_pixel_value = (char)atoi(line);

	/* TODO: pgm_info.pixels icin malloc() ile yer ayiralim. width*height kadar yer.
	 * Bir piksel 1 bayt yer istiyor, unutmayalim. XX
	 */
	pgm_info.pixels = malloc(sizeof(char) * (pgm_info.height) * (pgm_info.width));

	/* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
	 * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin. XX*/
	if (pgm_info.pixels == NULL) {
		fclose(pgm);
		pgm_info.error = PGM_ERROR_MALLOC;
	}

	/* TODO: 2 farkli dosya bicimi, 2 farkli okuma bicimi.
	 * P2 yani ASCII olanda dosyayi fgets() ile satir satir okuyoruz.
	 * Okudugumuz satirin sonundaki '\n' karakterini kaldiriyoruz
	 * ve elimizde kalan string'i atoi() ile sayiya cevirip pixels
	 * dizisine kaydediyoruz.
	 *
	 * P5 yani binary olanda ise dogrudan fread() ile bir kerede pixels'e
	 * okuma yapiyoruz.
	 */
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM fgets ile satırı oku atoi fonksiyonu ile sayıya çevir döngü ile */
		while (i < (pgm_info.width * pgm_info.height)) {
			fgets(line, sizeof(line), layn);
			line[sterlen(line) - 1] = '\0';
			pgm_info.pixels[i] = (char *)atoi(line);
		}
		break;
	case '5':
		/* TODO: Binary PGM read ile widthheight ı oku ve reade yazdır */
		read = fread(line, sizeof(line), LINE_MAX, layn);
		break;
	}
	fclose(pgm);

	/* Eger dogru okuma yapamadiysaniz programiniz assert() sayesinde
	 * yarida kesilecek. */
	printf("Read %d bytes. (Should be: %d)\n", read, pgm_info.width * pgm_info.height);
	assert(read == (pgm_info.width * pgm_info.height));

	return pgm_info;
}

int pgm_write(const char *filename, PGMInfo pgm_info)
{
	/* Bu fonksiyon filename stringiyle verilen dosyayi write kipinde acarak
	 * pgm_info'nun icindeki baslik ve piksel bilgilerini dosyaya yazar.
	 * Boylece yeni bir PGM resim dosyasi diske kaydedilmis olur.
	 *
	 * Fonksiyon herhangi bir hatada 1, basari durumunda 0 dondurmelidir.
	 */

	/* TODO: Dosyayi write kipinde acin. Acma basarisiz olursa fonksiyon
	 * 1 dondurerek sonlanmalidir. */
	int i;
	FILE *pgm = fopen(filename, "w");

	/* TODO: Baslik yapisini fprintf() ile dosyaya yazin xx */
	fprintf(pgm, "%s \n%s \n%d %d \n%d \n", pgm_info.signature, pgm_info.comment, pgm_info.width, pgm_info.height, pgm_info.max_pixel_value);
	/* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM (ipucu: fprintf) */
		for (i = 0; i < (pgm_info.width * pgm_info.height); i++) {
			fprintf(pgm, "%d\n", pgm_info.pixels[i]);
		}
		break;
	case '5':
		/* TODO: Binary PGM (ipucu: fwrite) */
		fwrite(pgm_info.pixels, sizeof(char), pgm_info.width * pgm_info.height, pgm);
		break;

	}
	/* Dosyayi kapatalim. */
	fclose(pgm);
	return 0;
}
