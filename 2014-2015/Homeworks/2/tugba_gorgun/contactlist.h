/*
 * contactlist.h
 *
 *  Created on: 29 Eki 2014
 *      Author: tugbagorgun
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define MAX_CONTACT_LIST_SIZE 2
struct Contact {
	char PhoneNumber[50];
	char FirstName[50];
	char LastName[50];
	char EMail[50];
} newContact;

struct ContactList {
	struct Contact Book[MAX_CONTACT_LIST_SIZE];
	int BookIndex;
} myContactList;

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
