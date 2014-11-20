/*
 * contactlist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"

void insert_new_contact(struct ContactList *clPtr)
{
	getchar();
	//Menü seçimi yaparken enter tuşuna basıldığında hafızada kalıyor. getchar() tek seferlik çalıştırıldığında son girilen tuşu hafızadan siler.
	if (clPtr->Count >= SIZE) {
		printf("Liste dolu! \n");
		return;
	}

	char c;
	int i = 0;
	struct Contact newContact;
	printf("Ad : ");
	while ((c = getchar()) != '\n' && c != EOF) {
		newContact.Name[i] = c;
		i++;
	}
	i = 0;
	printf("\nSoyad : ");
	while ((c = getchar()) != '\n' && c != EOF) {
		newContact.LastName[i] = c;
		i++;
	}
	i = 0;
	printf("\nTelefon : ");
	while ((c = getchar()) != '\n' && c != EOF) {
		newContact.Phone[i] = c;
		i++;
	}
	i = 0;
	printf("\nEposta : ");
	while ((c = getchar()) != '\n' && c != EOF) {
		newContact.Email[i] = c;
		i++;
	}

	clPtr->Contacts[clPtr->Count] = newContact;
	clPtr->Count = clPtr->Count + 1;
	printf("\n");
}

void print_contact(struct Contact *cPtr)
{
	printf("Ad Soyad : %s %s, Tel : %s, E-POsta : %s \n", cPtr->Name, cPtr->LastName, cPtr->Phone, cPtr->Email);
}

void print_contact_list(struct ContactList *clPtr)
{
	getchar();
	int i;
	for (i = 0; i < clPtr->Count; i++) {
		print_contact(&(clPtr->Contacts[i]));
	}
}
