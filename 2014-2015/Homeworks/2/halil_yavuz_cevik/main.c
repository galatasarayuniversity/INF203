/*
 * main.c
 *
 */
#include <stdio.h>
#include "contactlist.h"

int main(int argc, char *argv[]) {


	struct ContactList cl1;

	//ilk kişiden başlamak için counter'ı telefon defterimizin ilk kişisine atıyoruz
	cl1.counter = 0;

	while (1) {

		printf("\nContact List\n");
		printf("------------\n");
		printf("  [0]: Insert New Contact\n");
		printf("  [1]: Print Contact List\n");

		int decision;

		scanf("%d", &decision);

		switch (decision) {

		case 0:

			insert_new_contact(&cl1);
			break;

		case 1:

			print_contact_list(&cl1);

			break;

		}
	}


	return 0;
}
