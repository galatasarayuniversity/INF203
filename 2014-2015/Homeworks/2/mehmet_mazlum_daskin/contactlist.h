
#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define MAX 20
#include<string.h>

struct Contact {

	char isim[50];
	char soyad[50];
	char eposta[50];
	char phone[50];

};

struct ContactList {
	struct Contact kisiler[MAX];
	int sayac;

};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
