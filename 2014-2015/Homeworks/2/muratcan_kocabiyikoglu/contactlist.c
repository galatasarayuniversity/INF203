#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	printf("Ad Soyad: %s %s, Tel: %s, E-posta: %s \n", cPtr->Ad, cPtr->Soyad, cPtr->Telefon, cPtr->Mail);
}

void print_contact_list(struct ContactList *clPtr)
{
	int sayi = clPtr->sayac;
	int i;
	for (i = 0; i < sayi; i++) {
		print_contact(&clPtr->defter[i]);
	}

}

void insert_new_contact(struct ContactList *clPtr)
{
	int i = clPtr->sayac;
	printf("\nAdinizi giriniz : ");
	scanf("%s", &clPtr->defter[i].Ad[0]);
	printf("\nSoyadinizi giriniz : ");
	scanf("%s", &clPtr->defter[i].Soyad[0]);
	printf("\nTelefon numaranizi giriniz : ");
	scanf("%s", &clPtr->defter[i].Telefon[0]);
	printf("\nE-posta adresiniz giriniz : ");
	scanf("%s", &clPtr->defter[i].Mail[0]);
}
