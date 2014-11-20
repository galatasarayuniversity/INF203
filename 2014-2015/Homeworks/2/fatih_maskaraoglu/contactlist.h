/*
 * contactlist.h
 *
 */
#include <stdio.h>
#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#include <stdlib.h>
#include <string.h>

typedef struct Contact {
	char ad[50];
	char soyad[50];
	char numara[50];
	char eposta[50];

} telefon;

/*
typedef struct ContactList {
	struct Contact insanlar;
	insanlar= (telefon*) malloc(sizeof(telefon)*kps);

};
*/
void print_contact(struct Contact *insanlar);
void insertnewcontact(struct Contact *insanlar);

#endif				/* CONTACTLIST_H_ */
