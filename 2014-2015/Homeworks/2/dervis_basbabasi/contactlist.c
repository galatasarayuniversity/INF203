/*
 * contactlist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	/* TODO */

	printf("Last name is %s\n", cPtr->LastName);
	printf("Name is %s\n", cPtr->FirstName);
	printf("Phone number is %s\n", cPtr->PhoneNumber);
	printf("Email is %s\n", cPtr->Email);
	printf("\n\n\n");
}

void print_contact_list(struct ContactList *clPtr)
{
	/* TODO */
	int i;
	for (i = 0; i < (clPtr->count); i++) {
		printf("PERSON NO : %d ###############################\n", i + 1);
		print_contact(&clPtr->List[i]);
	}
}

void insert_new_contact(struct ContactList *clPtr)
{
	/* TODO */
	int i;
	clPtr->count++;

	printf("please enter the last name\n");
	scanf("%20s", clPtr->List[clPtr->count - 1].LastName);

	printf("please enter the first name\n");
	scanf("%20s", clPtr->List[clPtr->count - 1].FirstName);

	printf("please enter your phone number\n");
	scanf("%20s", &clPtr->List[clPtr->count - 1].PhoneNumber);

	printf("please enter email\n");
	scanf("%20s", clPtr->List[clPtr->count - 1].Email);

	for (i = 0; i < (clPtr->count - 1); i++) {
		if (strcmp(clPtr->List[clPtr->count - 1].Email, clPtr->List[i].Email) == 0) {
			clPtr->count--;
			printf("Error ! You must use another e-mail...\n");
		}
	}

}
