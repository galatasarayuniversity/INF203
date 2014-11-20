/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define MAX 20

struct Contact {
	char ad[51];
	char soyad[51];
	char tel[51];
	char posta[51];
};

struct ContactList {
	/* TODO */
	struct Contact contacts[MAX];
	int counter;

};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
