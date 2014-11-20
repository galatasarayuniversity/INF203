
#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define SAYAC 20

struct Contact {
	char telno[51];
	char ad[51];
	char soyad[51];
	char eposta[51];
};

struct ContactList {
	struct Contact kisiler[20];
	int sayac;
} liste;

void print_contact(struct Contact *cPtr);
void print_contact_list(struct ContactList *clPtr);

void insert_new_contact(struct ContactList *clPtr);

#endif
