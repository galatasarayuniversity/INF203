/*
 * contactlist.c
 */

#include <stdio.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	printf("Ad Soyad:%s %s, Telefon:%s, e-posta:%s\n", cPtr->ad, cPtr->soyad, cPtr->tel, cPtr->posta);

}

void print_contact_list(struct ContactList *clPtr)
{

	int i;
	for (i = 0; i < clPtr->counter; ++i) {
		print_contact(&clPtr->contacts[i]);
		struct Contact;

	}
}

void insert_new_contact(struct ContactList *clPtr)
{

	struct Contact *next = &clPtr->contacts[clPtr->counter];

	printf("Ad: ");
	scanf("%50s", next->ad);

	printf("Soyad: ");
	scanf("%50s", next->soyad);

	printf("Telefon: ");
	scanf("%50s", next->tel);

	printf("e-posta: ");
	scanf("%50s", next->posta);

	clPtr->counter++;
}
