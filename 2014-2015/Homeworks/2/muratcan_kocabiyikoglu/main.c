#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"

int clean_stdin()
{
	while (getchar() != '\n') ;
	return 1;
}

//Kullanıcının menüdeyken sadece integer girmesini istediğim için bir do while döngüsü yazdım o düngünün kontrolü için bu fonksiyonu ekledim - stackoverflow
int main(int argc, char *argv[])
{
	int secim = 4;		// while dan çıkabilmesi için gereken değişken
	struct ContactList rehber;	// contactlist de tanımını yaptğımız ContactList in buraya bir örneğini çıkardık
	rehber.sayac = 0;	// rehberde hiç bir kaıt olmadığı için sayacını sıfıra ayarladık
	int success, i, n, tekrar;

	while (secim != 3) {

		printf("\n[0]: Insert New Contact\n");
		printf("[1]: Print Contact List\n");
		printf("[2]: Exit\n");
		success = 0;	// Eğer kullanıcı integer girdiyse değişken 1 oluyor ve switch döngüsüne girebiliyor
		int rows = 0;
		char c;
		do {

		} while (((scanf("%d%c", &rows, &c) != 2 || c != '\n') && clean_stdin()) || rows < 0 || rows > 2);
		//int rows dan buraya kadar yazılan kod kullanıcının sadece 0 -2 arası sayı girmesini sağlamak için koyuldu - kaynak : stackoverflow :
		//http://stackoverflow.com/questions/14099473/how-to-scanf-only-integer-and-repeat-reading-if-the-user-enter-non-numeric-chara
		success = 1;
		if (success == 1) {

			switch (rows) {
			case 0:
				if (rehber.sayac == CAPACITY) {
					printf("Rehber maksimum kapasitesine ulaştı. Yeni kişi eklenemez!\n");
					break;
					//rehber kapasitesine ulaştığında daha fazla kayıt almayacak ve hep bu hatayı bastıracak
				} else {
					secim = 4;
					insert_new_contact(rehber.defter);
					if (rehber.sayac > 0) {
						for (i = 0; i < rehber.sayac; ++i) {
							tekrar = 0;
							for (n = 0; n < LIMIT; ++n) {
								if (rehber.defter[rehber.sayac].Mail[n]
								    == rehber.defter[i].Mail[n]) {
									tekrar++;
								} else {
									tekrar = 0;
								}
							}
							if (tekrar == LIMIT) {
								printf
								    ("\nBu mail adresi ile daha once giris yapildi. Lütfen yeni bir giris deneyiniz!\n");
								for (n = 0; n < LIMIT; ++n) {
									rehber.defter[rehber.sayac].Mail[n] = "";
									rehber.defter[rehber.sayac].Ad[n] = "";
									rehber.defter[rehber.sayac].Soyad[n] = "";
									rehber.defter[rehber.sayac].Telefon[n] = "";
								}
								//BONUS : aynı mail ile kayıt yapmak isteyenlerin kaydı silinecek ve sayac ilerlemeyecek
								rehber.sayac--;
								break;
							}
						}
					}
					rehber.sayac++;
					break;
					//Yeni kayıtın alınması ve aynı mail ile kayıt yapılıp yapılmadığının kontrol edilmesi
				}

			case 1:
				if (rehber.sayac == 0) {
					printf("Gösterilecek bir liste yok !\n\n");
					break;
				} else {
					print_contact_list(rehber.defter);
					break;
				}
				//hiç kayıt yapılmadıysa yukarıdaki hata çıkacak yoksa eldekileri gösterecek
			case 2:
				secim = 3;
				break;
				//2 numara seçilirse secimi 3 eşitleyecek ve döngüden çıkabilecek
			default:
				break;
			}
		} else {
		}

	}

	return 0;
}
