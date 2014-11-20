
#include <stdio.h>
#include "contactlist.h"
#include<string.h>

void print_contact(struct Contact *cPtr)
{

	printf("isim : %s,soyad %s,phone %s , eposta %s", cPtr->isim, cPtr->soyad, cPtr->phone, cPtr->eposta);

}

void print_contact_list(struct ContactList *clPtr)
{
	int i = 0;
	int l;

	for (i = 0; i < clPtr->sayac; i++) {
		printf("\n");

		/*son indeksi diğer elemamlarla karşılaştırmaya çalıştım */
		for (l = 0; l < clPtr->sayac - 1; l++) {
			if (clPtr->kisiler[clPtr->sayac - 1].eposta == clPtr->kisiler[l].eposta) {
				printf("aynı eposta adresine  sahip kişileri ekleyemezsiniz \n");

			}

		}

		printf("\n");

		print_contact(&clPtr->kisiler[i]);

	}

}

void insert_new_contact(struct ContactList *clPtr)
{
	if (clPtr->sayac < 20) {
		printf("name:");
		scanf("%s", clPtr->kisiler[clPtr->sayac].isim);
		printf("soyad:");
		scanf("%s", clPtr->kisiler[clPtr->sayac].soyad);
		printf("eposta:");
		scanf("%s", clPtr->kisiler[clPtr->sayac].eposta);
		printf("numara:");
		scanf("%s", clPtr->kisiler[clPtr->sayac].phone);
	} else
		printf("liste doludur");
	clPtr->sayac++;

}
