/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define MAX 20
#include<stdlib.h>
#include<stdio.h>

struct Contact {

	char firstname[50];
	char lastname[50];
	char number[50];
	char mail[50];

};

struct ContactList {

	int counter;
	struct Contact person[20];

};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
