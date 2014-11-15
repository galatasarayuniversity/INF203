#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

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
	PGMInfo pgm_info = { pgm_info.error = 0 };

	/* Dosyadaki satirlari okumak icin bir tampon. */
	char line[LINE_MAX];
	int i = 0;
	int read = 0;
	int len = 0;

	/* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
	 * uyesini PGM_ERROR_READ yapip fonksiyonu return ettirin.
	 */
	FILE *pgmFile = fopen(filename, "rb");
	if (pgmFile == NULL) {
		perror("cannot open file to read");
		pgm_info.error = PGM_ERROR_READ;
		return pgm_info;
	}
	/* Dosyadan tam bir satiri line tamponuna okuyalim. */
	fgets(line, sizeof(line), pgmFile);
	/* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim. */
	sscanf(line, "%s ", pgm_info.signature);

	/* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
	 * PGM_ERROR_SIGNATURE yapip fonksiyonu return ettirin.
	 */
	if (strcmp(pgm_info.signature, "P2") == 0 && strcmp(pgm_info.signature, "P5") == 0) {
		pgm_info.error = PGM_ERROR_READ;
		fclose(pgmFile);
		return pgm_info;
	}

	/* Comment satirini oku. */
	fgets(pgm_info.comment, sizeof(line), pgmFile);
	/* TODO: En ve boyu oku */
	fscanf(pgmFile, "%d %d\n", &pgm_info.width, &pgm_info.height);
	/* TODO: Max piksel degerini oku */
	fscanf(pgmFile, "%d\n", &pgm_info.max_pixel_value);
	/* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
	 * Bir piksel 1 bayt yer istiyor, unutmayalim.
	 */
	pgm_info.pixels = (unsigned char *)malloc((pgm_info.height * pgm_info.width) * pgm_info.max_pixel_value);

	/* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
	 * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin.*/
	if (pgm_info.pixels == NULL) {
		perror("memory allocation failure");
		fclose(pgmFile);
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
		while (!feof(pgmFile)) {

			//if(read = atoi(fgets(line, sizeof(line) , pgmFile)) != '\n'){
			//       pgm_info.pixels[i] = read;
			//       i++;
			//}
			//read = fscanf (pgmFile,"%d",&i);
			fgets(line, sizeof(line), pgmFile);
			len = strlen(line);
			line[len] = '\0';
			pgm_info.pixels[i] = (char)atoi(line);
			i++;
			read++;
		}
		read--;
		break;
	case '5':
		/* TODO: Binary PGM */

		read = fread(pgm_info.pixels, 1, pgm_info.width * pgm_info.height, pgmFile);

		//  read = ...;
		break;
	}
	fclose(pgmFile);

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
	int i, j;
	FILE *pgmFileS = fopen(filename, "wb");
	if (pgmFileS == NULL) {
		perror("cannot open file to write");
		return 1;
	}

	/* TODO: Baslik yapisini fprintf() ile dosyaya yazin */
	fprintf(pgmFileS, "%s\n", pgm_info.signature);
	fprintf(pgmFileS, "%s\n", pgm_info.comment);
	fprintf(pgmFileS, "%d %d\n", pgm_info.width, pgm_info.height);
	fprintf(pgmFileS, "%d\n", pgm_info.max_pixel_value);

	/* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
	switch (pgm_info.signature[1]) {
	case '2':
		/* TODO: ASCII PGM (ipucu: fprintf) */
		/*for (i = 0; i < pgm_info.height;i++) {
		   for (j = 0; j < pgm_info.width ; j++)
		   fprintf(pgmFileS,"%d ",(pgm_info.pixels[i * pgm_info.width + j]));
		   fprintf(pgmFileS,"\n");
		   } */
		for (i = 0; i < pgm_info.height * pgm_info.width; i++) {
			fprintf(pgmFileS, "%d\n", pgm_info.pixels[i]);
		}

		break;
	case '5':
		/* TODO: Binary PGM (ipucu: fwrite) */
		fwrite(pgm_info.pixels, 1, pgm_info.width * pgm_info.height, pgmFileS);
		break;

	}
	/* Dosyayi kapatalim. */
	fclose(pgmFileS);

	return 0;
}
