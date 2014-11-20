/*
 * main.c
 *
 */

/* TODO: Gerekli baslik dosyalarini include edin. */
#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"

int main(int argc, char **argv)
{

	struct ContactList cl;
	/*Sonsuz döngüye menüyü koyuyoruz ki her seferinde karşımıza
	 * çıkmış olsun
	 */
	while (1) {
		printf("Contact List \n");
		printf("-------------\n");
		printf("[0]:  Insert New Contact \n");
		printf("[1]:  Print Contact List \n");
		printf("[2]:  EXIT \n");
		char c;
		c = getchar();
		if (c == '0') {
			insert_new_contact(&cl);
		}
		if (c == '1') {
			print_contact_list(&cl);
		}
		if (c == '2') {
			break;
		}
	}
	return (0);
}
