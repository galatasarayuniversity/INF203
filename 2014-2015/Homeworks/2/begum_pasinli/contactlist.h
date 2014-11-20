/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define MAX 50
#define SIZE 20

struct Contact {
	char Name[MAX];
	char LastName[MAX];
	char Phone[MAX];
	char Email[MAX];
};

struct ContactList {
	int Count;
	struct Contact Contacts[SIZE];
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
