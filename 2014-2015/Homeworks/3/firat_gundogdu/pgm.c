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
	int i = 0;
	int read = 0;

	FILE *fileptr;

	/* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
	 * uyesini PGM_ERROR_READ yapip fonksiyonu return ettirin.
	 */

	fileptr = fopen(filename, "r");
	if (fileptr == NULL) {
		pgm_info.error = 1;
		return pgm_info;
	}

	/* Dosyadan tam bir satiri line tamponuna okuyalim. */
	fgets(line, sizeof(line), fileptr);
	/* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim. */
	sscanf(line, "%s ", pgm_info.signature);

	/* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
	 * PGM_ERROR_SIGNATURE yapip fonksiyonu return ettirin.
	 */
	if (pgm_info.signature[1] != '2' && pgm_info.signature[1] != '5') {
		fclose(fileptr);
		pgm_info.error = 2;
		printf("%s\n", pgm_info.signature);
		return pgm_info;
	}

	/* Comment satirini oku. */
	fgets(pgm_info.comment, sizeof(line), fileptr);

	/* TODO: En ve boyu oku */
	fgets(line, sizeof(line), fileptr);
	sscanf(line, "%d %d", &pgm_info.width, &pgm_info.height);

	/* TODO: Max piksel degerini oku */
	fgets(line, sizeof(line), fileptr);
	sscanf(line, "%hhu", &pgm_info.max_pixel_value);

	/* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
	 * Bir piksel 1 bayt yer istiyor, unutmayalim.
	 */

	pgm_info.pixels = malloc(pgm_info.width * pgm_info.height);

	/* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
	 * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin.*/
	if (pgm_info.pixels == NULL) {
		fclose(fileptr);
		pgm_info.error = 3;
		return pgm_info;
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
		/* TODO: ASCII PGM */
		while (fgets(line, sizeof(line), fileptr) != NULL) {
			line[strlen(line) - 1] = '\0';
			pgm_info.pixels[i] = (unsigned char)atoi(line);

			read += 1;

		}
		break;
	case '5':
		/* TODO: Binary PGM */
		read = fread(pgm_info.pixels, 1, pgm_info.width * pgm_info.height, fileptr);
		break;
	}
	fclose(fileptr);

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

	FILE *fileptr;
	int i;

	/* TODO: Dosyayi write kipinde acin. Acma basarisiz olursa fonksiyon
	 * 1 dondurerek sonlanmalidir. */
	fileptr = fopen(filename, "w");
	if (fileptr == NULL) {
		return 1;
	}

	/* TODO: Baslik yapisini fprintf() ile dosyaya yazin */
	fprintf(fileptr, "%s\n%s\n%d %d\n%hhu\n", pgm_info.signature, pgm_info.comment, pgm_info.width, pgm_info.height, pgm_info.max_pixel_value);

	/* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM (ipucu: fprintf) */
		for (i = 0; i < pgm_info.height * pgm_info.width; i++) {
			fprintf(fileptr, "%hhu", pgm_info.pixels[i]);
		}

		break;
	case '5':
		/* TODO: Binary PGM (ipucu: fwrite) */
		fwrite(pgm_info.pixels, 1, pgm_info.width * pgm_info.height, fileptr);
		break;

	}
	/* Dosyayi kapatalim. */
	fclose(fileptr);
	return 0;
}
