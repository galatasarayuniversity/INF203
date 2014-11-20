/*
 * main.c
 *
 */
#include <stdio.h>
#include "contactlist.h"

int main(int argc, char *argv[])
{
	int a;
	struct Contact dizi[N];
	struct Contact *cPtr;
	cPtr = &dizi[0];
	//      void print_contact_list(struct ContactList* clPtr);
	printf("Contact List\n");
	printf("_______________\n");
	printf("[0]: Insert New Contact\n[1]: Print Contact List\n[2]: Exit\n");
	printf("Sayı bekliyor...\n");
	scanf("%d:", &a);

	switch (a) {
	case 0:
		printf("Insert New Contact\n ");

		void insert_new_contact(struct ContactList *clPtr);
		break;
	case 1:
		printf("Print Contact List\n ");
		void print_contact_list(struct ContactList *clPtr);
		break;
	default:
		printf("Exit\n ");
		break;
	}

	return 0;
}
