/*
 * contactlist.c
 *
 *  Created on: 29 Eki 2014
 *      Author: tugbagorgun
 */

#include <stdio.h>
#include "contactlist.h"
#include <stdbool.h>
#include <string.h>

void print_contact(struct Contact *cPtr)
{
	printf("\nName/Surname: %s %s, Phone Number: %s, E-mail: %s", (*cPtr).FirstName, (*cPtr).LastName, (*cPtr).PhoneNumber, (*cPtr).EMail);
}

void print_contact_list(struct ContactList *clPtr)
{
	if ((*clPtr).BookIndex > 0) {
		int i = 0;
		for (i = 0; i < (*clPtr).BookIndex; i++) {
			print_contact(&(*clPtr).Book[i]);
		}
	} else {
		printf("Contact list is emtpy!");
	}
}

void insert_new_contact(struct ContactList *clPtr)
{

	printf("\nPlease type phone number: ");
	scanf("%50s", &newContact.PhoneNumber);
	printf("\nPlease type first name: ");
	scanf("%50s", &newContact.FirstName);
	printf("\nPlease type last name: ");
	scanf("%50s", &newContact.LastName);
	printf("\nPlease type email address: ");
	scanf("%50s", &newContact.EMail);

	if ((*clPtr).BookIndex < MAX_CONTACT_LIST_SIZE) {
		int i = 0;
		bool isExist = false;
		for (i = 0; i < (*clPtr).BookIndex; i++) {
			if (!strcmp((*clPtr).Book[i].EMail, newContact.EMail)) {
				printf("\nThis e-mail exists!");
				isExist = true;
				break;
			}
		}
		if (!isExist) {
			(*clPtr).Book[(*clPtr).BookIndex] = newContact;
			(*clPtr).BookIndex++;
			printf("\nSaved!");
		}
	} else {
		printf("\nContact list book is full!");
	}

}
