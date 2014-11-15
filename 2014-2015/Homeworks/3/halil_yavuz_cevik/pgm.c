/*
 * pgm.c
 *
 *  Created on: Nov 7, 2014
 *      Author: yc
 */

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

	/* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
	 * uyesini PGM_ERROR_READ yapip fonksiyonu return ettirin.
	 */

	FILE *fp = fopen(filename, "r");

	if (fp == NULL) {

		pgm_info.error = PGM_ERROR_READ;

		return pgm_info;

	}

	/* Dosyadan tam bir satiri line tamponuna okuyalim. */
	fgets(line, sizeof(line), fp);
	/* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim. */
	sscanf(line, "%s ", pgm_info.signature);

	/* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
	 * PGM_ERROR_SIGNATURE yapip fonksiyonu return ettirin.
	 */
	if (strcmp(pgm_info.signature, 'P2') != 0 && strcmp(pgm_info.signature, 'P5') != 0) {

		fclose(fp);
		pgm_info.error = PGM_ERROR_SIGNATURE;

		return pgm_info;

	}

	/* Comment satirini oku. */
	fgets(pgm_info.comment, sizeof(line), fp);

	/* TODO: En ve boyu oku */
	fscanf(fp, "%d", &pgm_info.height);
	fscanf(fp, "%d", &pgm_info.width);

	/* TODO: Max piksel degerini oku */
	fscanf(fp, "%c", &pgm_info.max_pixel_value);

	/* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
	 * Bir piksel 1 bayt yer istiyor, unutmayalim.
	 */
	pgm_info.pixels = (unsigned char *)malloc(sizeof(unsigned char));

	/* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
	 * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin.*/
	if (pgm_info.pixels == NULL) {

		pgm_info.error = PGM_ERROR_MALLOC;

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
		while (0) {;
		}
		break;
	case '5':
		/* TODO: Binary PGM */
		read = fread(pgm_info.pixels, pgm_info.width * pgm_info.height, 1, fp);
		break;
	}
	fclose(fp);

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
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {

		printf("Dosya yazma kipinde acilmadı\n");

		return 1;

	}

	/* TODO: Baslik yapisini fprintf() ile dosyaya yazin */

	fprintf(fp, filename);

	/* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM (ipucu: fprintf) */
		break;
	case '5':
		/* TODO: Binary PGM (ipucu: fwrite) */
		fwrite(pgm_info.pixels, pgm_info.height * pgm_info.width, 1, fp);
		break;

	}
	/* Dosyayi kapatalim. */
	fclose(fp);
	return 0;
}
