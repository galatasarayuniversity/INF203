/*
 * contactlist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contactlist.h"

FILE *pWrite;
FILE *pRead;
char dosyaadi[256];

void insertnewcontact(struct Contact *insanlar)
{
	int counter = 0;

	pWrite = fopen("defter.dat", "a");

	if (counter == 20) {
		perror("Kapasite dolu ");
		exit(EXIT_FAILURE);
	} else {
		counter++;
		printf("\nİsim: ");
		scanf("%s", insanlar[counter - 1].ad);
		printf("Soyisim: ");
		scanf("%s", insanlar[counter - 1].soyad);
		printf("Telefon no: ");
		scanf("%s", insanlar[counter - 1].numara);
		printf("E-mail: ");
		scanf("%s", insanlar[counter - 1].eposta);

		fprintf(pWrite, "%s\t%s\t%p\t%s\n", insanlar[counter - 1].ad, insanlar[counter - 1].soyad, insanlar[counter - 1].numara,
			insanlar[counter - 1].eposta);
		fclose(pWrite);

	}

}

void print_contact(struct Contact *insanlar)
{

	int x;

	printf("\n Kisiler:\n\n ");

	pRead = fopen("defter.dat", "r");

	if (pRead == NULL) {
		perror("Rehberin ici bos: ");
		exit(EXIT_FAILURE);
	} else {
		for (x = 0; x < 20; x++) {
			printf("\n(%d)\n", x + 1);
			printf("Ad: %s %s\n", insanlar[x].ad, insanlar[x].soyad);
			printf("Numara: %s\n", insanlar[x].numara);
			printf("E-mail: %s\n", insanlar[x].eposta);
		}
	}
	fclose(pRead);
}
