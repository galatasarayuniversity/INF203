/*
 * main.c
 *
 */

/* TODO: Gerekli baslik dosyalarini include edin. */
#include <stdio.h>
#include <string.h>
#include"contactlist.h"

int main(int argc, char *argv[])
{
	int answer;

	struct ContactList conlistPtr;	//new pointer declaration
	conlistPtr.ctr_regist = 0;

	do {
		printf("\nContact List \n");
		printf("------------\n");
		printf("[0]: Insert New Contact\n");
		printf("[1]: Print Contact List\n");
		printf("[2]: Exit\n");

		scanf("%d", &answer);

		switch (answer) {

		case 0:
			printf("Creating a new contact...\n");
			insert_new_contact(&conlistPtr);
			break;

		case 1:
			printf("Listing the created contacts...\n");
			print_contact_list(&conlistPtr);
			break;

		case 2:
			printf("...Terminating...\n");
			return 0;

		default:
			printf("Please enter a valid number\n");
			break;
		}
	} while (answer != 2);	//Loop will continue in case 0 and 1
	return 0;
}
