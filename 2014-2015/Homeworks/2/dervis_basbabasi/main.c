/*
 * main.c
 *
 */

/* TODO: Gerekli baslik dosyalarini include edin. */
#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"
//#include "contactlist.c"

int main(int argc, char *argv[])
{

	struct ContactList PhoneBook;
	int choice;

	PhoneBook.count = 0;

	do {
		printf("1) Insert New Contact\n");
		printf("2) Print Contact List\n");
		printf("3) Exit\n");

		scanf("%d", &choice);
		switch (choice) {
		case 1:	//new contact 
			if (PhoneBook.count == 100)
				printf("Phonebook is full...\n");
			else
				insert_new_contact(&PhoneBook);
			break;
		case 2:	//print contact list
			if (PhoneBook.count == 0)
				printf("Phonebook is empty...\n");
			else
				print_contact_list(&PhoneBook);
			break;
		case 3:
			printf("The Phonebook will now exit...\n");
			break;
		default:
			printf("Error...\n");
			break;
		}
	} while (choice != 3);
	//clrscr();

	return EXIT_SUCCESS;;
}
