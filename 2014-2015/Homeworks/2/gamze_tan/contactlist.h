/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define N 20

struct Contact {
	char phonenum[11];
	char name[50];
	char surname[50];
	char email[50];
};

struct ContactList {
	struct Contact contacts[N];
	int counter;

};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
