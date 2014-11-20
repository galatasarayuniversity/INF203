
#include <stdio.h>
#include <string.h>
#include "contactlist.h"

void print_contact(struct Contact *cPtr)
{

	printf("Ad Soyad: %s %s Tel: %s E-posta: %s \n", cPtr->ad, cPtr->soyad, cPtr->telno, cPtr->eposta);
}

void print_contact_list(struct ContactList *clPtr)
{

	int i;
	for (i = 0; i < clPtr->sayac; i++) {
		print_contact(&(clPtr->kisiler[i]));
	}
}

void insert_new_contact(struct ContactList *clPtr)
{

	int i;
	struct ContactList *clptr;
	clptr = &liste;
	int sayac = 0;

	for (i = 0; i < 20; i++) {
		int c;
		printf("Yeni kişi eklemek için sırayla ad, soyad, numara ve e-postasını aralarında boşluk bırakarak yazınız.\n");
		scanf("%50s %50s %15s %50s", &clptr->kisiler[i].ad, &clptr->kisiler[i].soyad, &clptr->kisiler[i].telno, &clptr->kisiler[i].eposta);

		sayac++;
		printf("Kayıtlı kişi sayısı: %d,  çıkmak için 0'a devam etmek için de herhangi bir tuşa basın. \n", sayac);
		c = getchar();

		if (c == 0) {
			break;
		}

		else
			continue;
	}
}
