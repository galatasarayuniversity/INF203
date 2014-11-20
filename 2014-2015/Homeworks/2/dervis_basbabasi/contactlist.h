/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
//#define MAX 50

struct Contact {
	/* TODO */
	char FirstName[20];
	char LastName[20];
	char PhoneNumber[20];
	char Email[20];
};

struct ContactList {
	/* TODO */
	int count;
	struct Contact List[100];
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);
void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
