/*
 * contactlist.c
 */

#include <stdio.h>
#include "contactlist.h"
#include <stdlib.h>

void print_contact(struct Contact *cPtr)
{
	struct Contact *yeni_ptr;

	FILE *dosya;

	fgets(yeni_ptr->ad, 20, dosya);
	fgets(yeni_ptr->soyad, 20, dosya);
	fgets(yeni_ptr->email, 20, dosya);
	fgets(yeni_ptr->tel, 20, dosya);
}

void print_contact_list(struct ContactList *clPtr)
{
	struct ContactList *liste;

	FILE *dosya = fopen("teldefteri.txt", "r");

	if (fgetc(dosya) == '#') {

		print_contact();
	} else {
		fclose(dosya);

	}

	while (!feof(dosya)) {
		fscanf(dosya, "%s%s%s", liste->kisi);
		printf("%s\t\t\t", liste->kisi);
	}

}

void insert_new_contact(struct ContactList *clPtr)
{

	struct ContactList *ilk;

	FILE *dosya = fopen("teldefteri.txt", "a");

	if ((dosya = fopen("teldefteri.txt", "a")) == NULL) {
		return;

	}

	printf("bir ad giriniz:");
	scanf("%s", ilk->kisi->ad);

	printf("bir soyad giriniz:");
	scanf("%s", ilk->kisi->soyad);

	printf("bir email giriniz:");
	scanf("%s", ilk->kisi->email);

	printf("bir telefon numarisi giriniz:");
	scanf("%s", ilk->kisi->tel);

	fprintf(dosya, "\n%s\t%s\t%s\t%s", ilk->kisi->ad, ilk->kisi->soyad, ilk->kisi->email, ilk->kisi->tel);

	fclose(dosya);

}
