/*
* contactlist.h
*
*/

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define N 20

struct Contact {
	char ad[51];
	char soyad[51];
	char tel[12];
	char email[51];
};

struct ContactList {
	struct Contact kisiler[N];
	int sayac;		// main.c de sıfırlandı
	/* TODO */
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
