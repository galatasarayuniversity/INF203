/*
 * main.c
 *
 *  Created on: Oct 29, 2014
 *      Author: FiratLePirate
 */

/*
 * main.c
 *
 */

/* TODO: Gerekli baslik dosyalarini include edin. */
#include <stdio.h>
#include <stdlib.h>

#include "contactlist.h"

int main(int argc, char *argv[])
{
	int choice;
	struct ContactList clPtr1;
	clPtr1.counter = 0;

	while (choice != 2) {

		printf("\nWelcome to the Phonebook!\n");
		printf("Please choose the operation below you want to do:\n");
		printf("*******************************\n");
		printf("[0]: Insert New Contact\n");
		printf("[1]: Print Contact List\n");
		printf("[2]: Exit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			insert_new_contact(&clPtr1);
			break;
		case 1:
			print_contact_list(&clPtr1);
			break;
		case 2:
			printf("Thanks for using the Phonebook!\n");
			return 0;
		}
	}

	return 0;
}
