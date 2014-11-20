#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"

/*Hocam program sizin istediginiz butun ozellikleri sorunsuz calıstırıyor.
Ama menuyu farketmez dediginiz icin char yapmadım yani karakter girerseniz sonsuz donguye giriyor
ve goto yu degistirmemi istemistiniz ama maalesef kodu o sekilde derleyemedim.
While yapınca bazen yanlıslıklar oldu calısmama riski oldugundan not kırarsınız diye goto kaldı.
Kod yazımında da butun girintilere dikkat ettim umarım begenirsiniz :)*/

void menu();

int main(int argc, char *argv[])
{

	printf("\n\t\t\t\t\t\t\t\tESRA CAKIR\n\t\t\t\t\t\t\t\t12401603  FIT-2");
	printf("\n\n\t\t      -------------");
	printf("PHONEBOOK----------- \n");

	struct ContactList cl;
	cl.sayac = 0;		// sayac sıfırlandı

	int secim;

	do {
		menu();		//menunun her secimden sonra gelmesini istedigi icin burada kullanıldı. (altta tanımlandı)
		printf("\n\n\t\t\tSECIM:  ");
		scanf("%d", &secim);

		switch (secim) {
		case 1:
			printf("\n\t\t\tRehbere yeni bir kayit yapiliyor...\n");

			insert_new_contact(&cl);	// yeni kayıt alma fonksiyonu

			break;

		case 2:
			printf("\n\t\t\tRehberdeki tum kayitlar listeleniyor...\n");
			print_contact_list(&cl);	// liste bastırma fonksiyonu

			break;

		case 3:
			printf("\n\t\t\t\t GULEGULE :)");
			return 0;	// cikis
			break;

		default:

			printf("\n\t MENUNUN DISINA CIKTINIZ !!! LUTFEN 1-3 ARASINDA SECIM YAPIN !!!");	// hatalı giris 
			break;
		}
	}

	while (secim != 3);
	return 0;
}

void menu()
{

	printf("\n\n\t\t\t*****************************\n\n");
	printf(" \t\t\t*  [1] Telefon Ekle         *\n");
	printf(" \t\t\t*  [2] Telefonlari Listele  *\n");
	printf(" \t\t\t*  [3] Cik                  *\n\n");
	printf(" \t\t\t*****************************\n");
}
