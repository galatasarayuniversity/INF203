/*
 * contactlist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"
#include <string.h>

void print_contact(struct Contact *cPtr)
{
	printf("\nAd Soyad %s %s, Tel: %s, E-Posta: %s\n", cPtr->name, cPtr->surname, cPtr->number, cPtr->mail);
}

void print_contact_list(struct ContactList *clPtr)
{
	int i;
	if (clPtr->sayac >= 0) {
		for (i = 0; i <= clPtr->sayac; i++) {
			print_contact(clPtr->kisi);
		}
	} else
		printf("The contact list is empty, no info to print!");
}

void insert_new_contact(struct ContactList *clPtr)
{
	char a[SIZE], b[SIZE], c[SIZE], d[SIZE];
	printf("\nEnter the name:\n");
	scanf("%50s", a);
	printf("Enter the surname:");
	scanf("%50s", b);
	printf("Enter the number:");
	scanf("%50s", c);
	printf("Enter the e-mail address:");
	scanf("%50s", d);

	if (clPtr->sayac <= CAP) {
		strcpy(clPtr->kisi[clPtr->sayac].name, a);
		strcpy(clPtr->kisi[clPtr->sayac].surname, b);
		strcpy(clPtr->kisi[clPtr->sayac].number, c);
		strcpy(clPtr->kisi[clPtr->sayac].mail, d);
		clPtr->sayac++;
	}

	int i;
	for (i = 0; i < clPtr->sayac; i++) {
		if (strcmp(clPtr->kisi[clPtr->sayac].mail, d) + 1)
			printf("E-mails are same, you can't enter the same e-mail!!!");
		return;
	}
	if (clPtr->sayac > CAP) {
		printf("Contact List is full! No more adding to the list!");
	}

}
