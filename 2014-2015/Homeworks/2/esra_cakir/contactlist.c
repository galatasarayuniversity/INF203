/*
* contactlist.c
*/

#include <stdio.h>
#include <string.h>
#include "contactlist.h"

void print_contact(struct Contact *clPtr)
{
	printf("\n\tAd soyad : %s %s ", clPtr->ad, clPtr->soyad);
	printf("\n\tTelefon : %s  ", clPtr->tel);
	printf("\n\tE-mail : %s  ", clPtr->email);
	// listeyi bas
}

void print_contact_list(struct ContactList *clPtr)
{

	if (clPtr->sayac == 0)
		printf("\n\t\t\tLISTE BOS!!!\n\t\t\tYeni kayit yapmayi deneyebilirsiniz!");	// bos liste hatası

	else {
		printf("\n\tTAM LISTE\n");

		int k;

		for (k = 0; k < (clPtr->sayac); k++) {
			printf("\n\n\t%d. Kayit\n\t ", k + 1);

			print_contact(&clPtr->kisiler[k]);	//kayitlar çekiliyor

		}
	}

	printf("\n");
	printf("\n");

}

void insert_new_contact(struct ContactList *clPtr)
{
	int i;
 bas:

	if (clPtr->sayac == N) {
		printf("\n\t\t\tLISTE DOLU!!! YENI KAYIT YAPAMAZSINIZ!!!\n ");
	}

	else {			/*yeni kayit bilgilerinin alinmasi */
		printf("\t\tAd:");
		scanf("%10s", clPtr->kisiler[clPtr->sayac].ad);

		printf("\n\t\tSoyad:");
		scanf("%10s", clPtr->kisiler[clPtr->sayac].soyad);

		printf("\n\t\tTelefon:");
		scanf("%20s", clPtr->kisiler[clPtr->sayac].tel);

		printf("\n\t\tE-mail:");
		scanf("%20s", clPtr->kisiler[clPtr->sayac].email);

		//BONUS 
		for (i = 0; i < clPtr->sayac; i++) {
			if (strcmp(clPtr->kisiler[clPtr->sayac].email, clPtr->kisiler[i].email) == 0)	//yeni kayıttaki mailin daha oncekilerle karsılastırılması
			{
				printf("\t\t\tHATA!!! Bu email daha once kullanilmis!\n");
				printf("\t\t\tYeni bir kayit yapmayi deneyin.\n");
				goto bas;	/* kayit almak icin basa döner,diger donguleri denedim ama cok karıstı calısmama riskini almak istemedim */
			}

		}
		clPtr->sayac++;	/* mail öncekilerden farklıysa sayacı arttırarak dizide yeni kayıt sırasına gider */

	}

}
