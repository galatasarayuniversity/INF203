/*
 * contactlist.c
 */

#include <stdio.h>
#include <string.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{
	//This function prints the values of struct elements...
	printf("\n");
	printf("\tName Surname : %s %s , Phone Number : %s , Email : %s", cPtr->name, cPtr->surname, cPtr->phone_number, cPtr->email);
	printf("\n");
}

void print_contact_list(struct ContactList *clPtr)
{
	//This function prints the Contact struct...
	printf("\n");

	if (clPtr->ctr_regist == 0) {
		printf("Contact list is empty ! " "(Don't forget to create at least one contact before listing them...)\n\n");
	} else {
		int i;
		for (i = 0; i < clPtr->ctr_regist; i++) {
			printf("%d. Registration : ", i + 1);
			print_contact(&clPtr->registration[i]);
		}
	}

}

void insert_new_contact(struct ContactList *clPtr)
{
	//This function creates Contact elements by inputs...

	if (clPtr->ctr_regist == N) {
		printf("The contact list is full !\n");
	} else {
		printf("Enter a Phone Number\n");
		scanf("%20s", clPtr->registration[clPtr->ctr_regist].phone_number);
		printf("Enter a name\n");
		scanf("%20s", clPtr->registration[clPtr->ctr_regist].name);
		printf("Enter a surname\n");
		scanf("%20s", clPtr->registration[clPtr->ctr_regist].surname);
		printf("Enter an email\n");
		scanf("%30s", clPtr->registration[clPtr->ctr_regist].email);

		clPtr->ctr_regist++;
	}

}
