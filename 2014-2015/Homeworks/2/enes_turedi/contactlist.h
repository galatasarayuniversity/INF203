/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define SIZE 50
#define CAP 20

struct Contact {
	char number[SIZE];
	char name[SIZE];
	char surname[SIZE];
	char mail[SIZE];
};

struct ContactList {
	struct Contact kisi[CAP];
	int sayac;
} *deneme_fonksiyon;

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
