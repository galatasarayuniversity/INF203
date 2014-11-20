/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

struct Contact {
	char ad[20];
	char soyad[20];
	char email[20];
	char tel[20];

};

struct ContactList {
	struct Contact *kisi;
	int sayac[20];
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);
void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
