/*
 * main.c

 *
 */
#include <stdio.h>
#include "contactlist.h"

/* TODO: Gerekli baslik dosyalarini include edin. */

int main(int argc, char *argv[])
{
	int choice = 0;
	int capacity = 20;
	struct ContactList cl;
	cl.counter = 0;
	while (choice != 2) {
		printf("\nContact List \n");
		printf("--------------\n");
		printf("  [0]: Insert New Contact\n");
		printf("  [1]: Print Contact List\n");
		printf("  [2]: Exit\n");
		printf("> ");

		scanf("%d", &choice);

		switch (choice) {
		case 0:
			if (cl.counter >= capacity) {
				printf("Contact list is full!\n");
			} else {
				insert_new_contact(&cl);
			}
			break;

		case 1:

			if (cl.counter == 0) {
				printf("Contact list is empty!\n");
			} else {
				print_contact_list(&cl);
			}
			break;
		}
	}
	return 0;
}
