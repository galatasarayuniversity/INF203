/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define N  20

struct Contact {
	char phone_number[20];
	char name[20];
	char surname[20];
	char email[30];
};

struct ContactList {
	struct Contact registration[N];	//N has declared at top
	int ctr_regist;		//the counter of registrations
};

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif				/* CONTACTLIST_H_ */
