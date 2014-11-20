
/* TODO: Include the necessary header files! */
#include <stdio.h>
#include "contactlist.h"
#include<string.h>

int main(int argc, char *argv[])
{
	//struct ContactList* amdb;

	struct ContactList defter;
	//amdb=&defter;
	defter.sayac = 0;
	int a;

	do {
		printf("\nContact List\n");
		printf("\n------------\n");
		printf("\n[0]: Insert New Contact\n");
		printf("\n[1]: Print Contact List\n");
		printf("\n[2]: Exit\n");
		scanf("%d", &a);

		switch (a) {
		case 0:
			//if (defter.sayac<=20)
			insert_new_contact(&defter);
			//else
			//printf("defter doludur");

			break;
		case 1:
			print_contact_list(&defter);
			//print_contact(&defter.kisiler);
			break;
		case 2:
			break;
		}
	} while (a == 0 || a == 1);

	return 0;
}
