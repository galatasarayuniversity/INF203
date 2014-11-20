/*
 * main.c
 *
 */

/* TODO: Gerekli baslik dosyalarini include edin. */

/* Merhaba Hocam
 * ContactList-> sayaca ulaşmaya çalıştığımda program direk "terminated" oluyor.
 * Nedenini anlayamadım ve dolayısıyla kodları tam olarak test edemedim.
 * Nedenini bulup bana anlatırsanız çok sevinirim.
 * İyi günler.
 */

#include <stdio.h>
#include "contactlist.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	deneme_fonksiyon->sayac = 0;

	int girdi;
	do {
		printf("\n Contact List \n ------------ \n");
		printf("[0]: Insert New Contact \n[1]: Print Contact List \n[2]: Exit\n");
		scanf("%d", &girdi);
		switch (girdi) {
		case 0:
			insert_new_contact(deneme_fonksiyon);
			break;
		case 1:
			print_contact_list(deneme_fonksiyon);
			break;
		case 2:
			break;

		}
	} while (girdi < 2);
	return 0;
}
