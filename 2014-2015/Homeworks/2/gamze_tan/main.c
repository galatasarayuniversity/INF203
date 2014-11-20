#include <stdio.h>
#include "contactlist.h"

int main(int argc, char *argv[])
{

	int number;
	struct ContactList new;
	new.counter = 0;

	do {

		printf("Contact List\n");

		printf("[0]: Insert New Contact\n");
		printf("[1]: Print Contact List\n");
		printf("[2]: Exit");

		printf("Enter a number :\n");
		scanf("%d", &number);
		switch (number) {
		case 0:

			insert_new_contact(&new);
			break;

		case 1:
			print_contact_list(&new);
			break;

		case 2:
			printf("Bye!!\n");
			return 0;
			break;

		default:
			printf("Error! Choose a number between 0 and 2!");
			break;
		}
	}
	while (number != 2);
	return 0;
}
