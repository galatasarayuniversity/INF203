/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define CAPACITY 20
#define LIMIT 50

struct Contact {
	char Telefon[LIMIT];
	char Ad[LIMIT];
	char Soyad[LIMIT];
	char Mail[LIMIT];
};

struct ContactList {
	struct Contact defter[CAPACITY];
	int sayac;
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
