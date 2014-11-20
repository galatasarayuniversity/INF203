/*
 * contactlist.h
 *
 *  Created on: Oct 19, 2014
 *      Author: onur
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define N 20
struct Contact {
	char ad[50];
	char soyad[50];
	char telNo[50];
	char email[50];
};
struct ContactList {
	struct Contact liste[N];
	int sayac;
};
void insert_new_contact(struct ContactList *clPtr);
void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);
void menu();

#endif				/* CONTACTLIST_H_ */
