/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

struct Contact {
	int sira;
	char ad[15];
	char soyad[15];
	char phone[12];
	char mail[25];
};

struct ContactList {
	struct Contact Contact[20];
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
