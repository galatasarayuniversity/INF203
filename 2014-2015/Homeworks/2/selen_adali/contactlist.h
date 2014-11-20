/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define N 20
struct Contact {
	char ad[50];
	char soyad[50];
	int telefon_no[50];
	char email[50];
};

struct ContactList {
	int sayac;
	struct Contact dizi[N];

};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
