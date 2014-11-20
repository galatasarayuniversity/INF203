/*
 * contactlist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{

	printf("Name: %s \t", cPtr->firstname);
	printf("Surname: %s \t", cPtr->lastname);
	printf("Phonenumber: %s \t", cPtr->number);
	printf("E-mail Adress: %s \n", cPtr->mail);

}

void print_contact_list(struct ContactList *clPtr)
{
	/* TODO */
	int i;

	if (clPtr->counter == 0) {
		printf("Phonebook is empty! Please first, insert a new contact!\n");
	}

	else

		for (i = 0; i < clPtr->counter; i++) {
			printf("%d.\t", i + 1);
			print_contact(&clPtr->person[i]);
		}
}

void insert_new_contact(struct ContactList *clPtr)
{

	/* TODO */
	char first_name_string[50];
	char last_name_string[50];
	char number_string[50];
	char mail_string[50];
	int j;

	if (clPtr->counter == 20) {
		printf("Phonebook is full!!!\n");
		return;
	}

	else

		clPtr->counter++;
	printf("Please enter the name of contact:\n");
	scanf("%s", &first_name_string);
	printf("Please enter the surname of contact:\n");
	scanf("%s", &last_name_string);
	printf("Please enter the phone number of contact in the form of (05XXXXXXXXX):\n");
	scanf("%s", &number_string);
	printf("Please enter the e-mail adress of contact:\n");
	scanf("%s", &mail_string);

	for (j = 0; j < clPtr->counter; j++) {

		if (strcmp(clPtr->person[j - 1].mail, mail_string) == 0) {
			printf("This e-mail adress is already belong another contact!\n");
			printf("Please insert a new contact with different e-mail adress!!\n");
			clPtr->counter--;
			return;
		}

		else

			strcpy(clPtr->person[clPtr->counter - 1].firstname, first_name_string);
		strcpy(clPtr->person[clPtr->counter - 1].lastname, last_name_string);
		strcpy(clPtr->person[clPtr->counter - 1].number, number_string);
		strcpy(clPtr->person[clPtr->counter - 1].mail, mail_string);

	}

	printf("Informations of the contact you entered are: \n");
	print_contact(&clPtr->person[clPtr->counter - 1]);

}
