/*
 * contactlist.c
 *
 *  Created on: Oct 19, 2014
 *      Author: onur
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactlist.h"

void insert_new_contact(struct ContactList *clPtr)
{
	int i, c = 1;
	printf("Lutfen bir isim giriniz:");
	scanf("%20s", clPtr->liste[clPtr->sayac].ad);
	printf("Lutfen bir soyisim giriniz:");
	scanf("%20s", clPtr->liste[clPtr->sayac].soyad);
	printf("Lutfen bir telefon numarasi giriniz:");
	scanf("%20s", clPtr->liste[clPtr->sayac].telNo);

	printf("Lutfen bir email giriniz:");
	scanf("%30s", clPtr->liste[clPtr->sayac].email);
	//BONUS
	for (i = 0; i < clPtr->sayac; i++) {
		c = c * strcmp(clPtr->liste[clPtr->sayac].email, clPtr->liste[i].email);
	}
	if (c == 0) {
		printf("\nLutfen gecerli bir e-mail adresi giriniz. Menuye yonlendiriliyorsunuz...\n");
		clPtr->liste[clPtr->sayac].ad[0] = '\0';
		clPtr->liste[clPtr->sayac].soyad[0] = '\0';
		clPtr->liste[clPtr->sayac].telNo[0] = '\0';
		clPtr->liste[clPtr->sayac].email[0] = '\0';
		clPtr->sayac--;
	}

}

void print_contact(struct Contact *cPtr)
{
	printf("Ad Soyad:%s %s ,Tel: %s ,E-mail: %s\n", cPtr->ad, cPtr->soyad, cPtr->telNo, cPtr->email);
}

void print_contact_list(struct ContactList *clPtr)
{
	int i;
	for (i = 0; i < clPtr->sayac; i++) {
		struct Contact *cPtr;
		cPtr = &clPtr->liste[i];
		print_contact(cPtr);
	}
}

void menu()
{
	printf("Contact List\n-------------------------\n[0]Insert New Contact\n[1]Print Contact List\n[2]Exit\n");
}
