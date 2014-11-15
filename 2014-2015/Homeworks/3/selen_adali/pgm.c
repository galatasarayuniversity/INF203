//Kodum çalışmıyor çünkü atoi ile pointer struct elemanın dönüşümünü yapamadım.

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
	FILE *filepointer;
	filepointer = fopen(filename, "r");
	if (filepointer == NULL) {
		pgm_info.error = PGM_ERROR_READ;
		return pgm_read(filename);
	}
	/* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
	 * uyesini PGM_ERROR_READ yapip fonksiyonu return ettirin.
	 */

	/* Dosyadan tam bir satiri line tamponuna okuyalim. */
	fgets(line, sizeof(line), filepointer);
	/* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim. */
	sscanf(line, "%s ", pgm_info.signature);

	/* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
	 * PGM_ERROR_SIGNATURE yapip fonksiyonu return ettirin.
	 */

	if (pgm_info.signature[1] != '2' && pgm_info.signature[1] != '5') {
		fclose(filepointer);
		pgm_info.error = PGM_ERROR_SIGNATURE;
	}

	/* Comment satirini oku. */
	fgets(pgm_info.comment, sizeof(line), filepointer);
	//fgets(pgm_info.height, sizeof(line), filepointer);
	//fgets(pgm_info.width, sizeof(line), filepointer);

	/* TODO: En ve boyu oku */
	fgets(line, sizeof(line), filepointer);
	if (line[0] == '#') {

		line[1] = pgm_info.height;
		//pgm_info.height=atoi(line); atoi kullanımında hata aldığım için kodu bu şekilde bıraktım.
		line[2] = pgm_info.width;

		fgets(line[1], sizeof(line), filepointer);
		fgets(line[2], sizeof(line), filepointer);
		i++;
	}
	/* TODO: Max piksel degerini oku */
	fgets(line[LINE_MAX], sizeof(line), filepointer);
	/* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
	 * Bir piksel 1 bayt yer istiyor, unutmayalim.
	 */
	pgm_info.pixels = malloc(sizeof(char) * pgm_info.width * pgm_info.height);
	/* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
	 * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin.*/
	if (pgm_info.pixels == NULL) {
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
		/* TODO: ASCII PGM */
		while (i < pgm_info.height * pgm_info.width) {
			fgets(line, sizeof(line), filepointer);
			pgm_info.pixels[i] = atoi(line);
			i++;
		}
		line[LINE_MAX - 1] = '\0';
		break;
	case '5':
		/* TODO: Binary PGM */
		read = fread(pgm_info.pixels, sizeof(line), pgm_info.width * pgm_info.height, filepointer);
		break;
	}
	fclose(filepointer);

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
	FILE *filepointer;
	filepointer = fopen(filename, "w");
	if (filepointer == 0) {
		return 1;
	}

	/* TODO: Dosyayi write kipinde acin. Acma basarisiz olursa fonksiyon
	 * 1 dondurerek sonlanmalidir. */

	/* TODO: Baslik yapisini fprintf() ile dosyaya yazin */
	fprintf(filepointer, "%s-%d-%d", pgm_info.signature, pgm_info.width, pgm_info.height);
	/* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
	int i = 0;
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM (ipucu: fprintf) */

		while (i < pgm_info.height * pgm_info.width) {
			fprintf(filepointer, "%d", pgm_info.pixels[i]);
			i++;
		}
		break;
	case '5':
		/* TODO: Binary PGM (ipucu: fwrite) */
		while (i < pgm_info.height * pgm_info.width) {
			fwrite(pgm_info.pixels, sizeof(char), pgm_info.width * pgm_info.height, filepointer);
		}
		break;

	}
	/* Dosyayi kapatalim. */
	fclose(filepointer);
	return 0;
}
