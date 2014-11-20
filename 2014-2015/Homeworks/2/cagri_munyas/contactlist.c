/*
 * contactlist.c
 */

#include <stdio.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	puts(ContactList->contact[i]->sira)
	    puts(ContactList->contact[i]->ad);
	puts(ContactList->contact[i]->soyad);
	puts(ContactList->contact[i]->phone);
	puts(ContactList->contact[i]->mail);
}

void print_contact_list(struct ContactList *clPtr)
{

	int i = 0;
	while (clPtr->contact[i]->sira == i + 1) {
		print_contact(*Contact[i]);
		i++;
	}
}

void insert_new_contact(struct ContactList *clPtr)
{

	while (clPtr->contact[i]->sira == i + 1) {
		i++;
	}
	if (i < 20) {
		clPtr->contact[i]->sira = i + 1;
		printf("%d. kişinin adını giriniz:\n", i + 1);
		fgets(clPtr->contact[i]->ad);
		printf("Soyadını giriniz:\n");
		fgets(clPtr->contact[i]->soyad);
		printf("Telefon numarasını giriniz:\n");
		scanf("%11d", clPtr->contact[i]->phone);
		printf("Mailini giriniz:\n");
		scanf("%s", ContactList->contact[i]->mail);
		i++;
	} else
		printf("Maksimum 20 kişi oluşturulabilir.\n");
}
