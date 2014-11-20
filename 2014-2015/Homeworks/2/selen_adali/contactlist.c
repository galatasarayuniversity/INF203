/*
 * contactlist.c
 */

#include <stdio.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	int sayac = 0;
	int j;
	struct Contact dizi[N];
	//struct Contact *cPtr;
	cPtr = &dizi[0];
	sayac++;

	for (j = 0; j < sayac; j++) {
		printf("\nTelefon Defterindeki Kayıtlar:\n");
		printf("Ad Soyad : %s %s \t Tel: %d \t E-posta: %s\n",
		       dizi[sayac - 1].ad, dizi[sayac - 1].soyad, dizi[sayac - 1].telefon_no, dizi[sayac - 1].email);
	}

}

void print_contact_list(struct ContactList *clPtr)
{
	int sayac = 0;
	int j;
	struct Contact ContactList[N];
	clPtr = &ContactList[N];
	for (j = 0; j < sayac; j++) {
		printf("\nTelefon Defterindeki Kayıtlar:\n");
		printf("Ad Soyad : %s %s \t Tel: %d \t E-posta: %s\n",
		       ContactList[sayac - 1].ad, ContactList[sayac - 1].soyad, ContactList[sayac - 1].telefon_no, ContactList[sayac - 1].email);
	}
}

void insert_new_contact(struct ContactList *clPtr)
{
	int sayac = 0;
	sayac++;
	struct Contact dizi[N];
	printf("İsim:");
	scanf("%s", dizi[sayac - 1].ad);
	printf("Soyad:");
	scanf("%s", dizi[sayac - 1].soyad);
	printf("Telefon Numarası:");
	scanf("%d", dizi[sayac - 1].telefon_no);
	printf("e-mail adresi:");
	scanf("%s", dizi[sayac - 1].email);
	printf("%d. kişinin bilgileri deftere eklendi.\n\n", sayac + 1);
}
