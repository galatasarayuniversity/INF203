/*
 * contactlist.c
 *
 */

#include <stdio.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	printf("%s\n" "%s\n" "%s\n" "%s\n", cPtr->name, cPtr->surname, cPtr->phonenum, cPtr->email);

}

void print_contact_list(struct ContactList *clPtr)
{

	if (clPtr->counter == 0) {
		printf("Contact list is empty!");
	} else {
		int j;
		for (j = 0; j < (clPtr->counter); j++) {
			printf("Name: %s\n", clPtr->contacts[j].name);
			printf("Surname: %s\n", clPtr->contacts[j].surname);
			printf("Phone Number: %s\n", clPtr->contacts[j].phonenum);
			printf("E-mail: %s\n", clPtr->contacts[j].email);
		}
	}
}

void insert_new_contact(struct ContactList *clPtr)
{
	int counter == 0;

	if (clPtr->counter == 20) {
		printf("Contact list is full!!");
	} else {

		printf("Name:\n");
		scanf("%s", clPtr->contacts[counter].name);

		printf("Surname:\n");
		scanf("%s", clPtr->contacts[counter].surname);

		printf("Phone Number:\n");
		scanf("%s", clPtr->contacts[counter].phonenum);

		printf("E-mail:\n");
		scanf("%s", clPtr->contacts[counter].email);

		clPtr->counter++;

	}
}
