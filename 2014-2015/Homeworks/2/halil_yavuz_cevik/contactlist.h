/*
 * contactlist.h
 *
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#define LENGTH 51
#define LENGTH_CNTCLST 20


//Telefon defterindeki her bir kişi için tanımlanacak struct

struct Contact {

	char tel_numb[LENGTH];
	char name[LENGTH];
	char surname[LENGTH];
	char mail[LENGTH];

};


//Telefon defterinin kendisi için tanımlanan struct

struct ContactList {
	int counter;
	struct Contact Contactlst[LENGTH_CNTCLST];
};


//Kullanıcak fonksiyonların prototipleri

void print_contact(struct Contact* cPtr);

void print_contact_list(struct ContactList* clPtr);

void insert_new_contact(struct ContactList* clPtr) ;

#endif /* CONTACTLIST_H_ */
