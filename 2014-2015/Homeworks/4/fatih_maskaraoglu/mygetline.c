/*
 * mygetlinenew.c
 *
 *  Created on: 1 Kas 2014
 *      Author: fatih
 */

/*
 * mygetline.c
 *
 *  Created on: 3 Kas 2014
 *      Author: fatih
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	// Okunan karakter

	buffer = malloc(sizeof(char) * sizeIncrement);
	char character;

	printf("bir karakter giriniz\n");
	scanf("%c", &character);

	while (character != 'n') {
		int sayac = 0;
		int a = 1;
		if (sayac == sizeIncrement * a) {
			sizeIncrement = 2 * sizeIncrement;
			buffer = (char *)realloc(buffer, sizeIncrement * sizeof(char));
			a++;
		} else {
			buffer[sayac] = character;
			sayac++;

			printf("bir karakter giriniz\n");
			scanf("%c", &character);
		}
	}

	return 0;
}

    /* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
     */

	/*TODO Okunan karakter sayisini arttir ve
	   Eğer okunan karakter sayısı malloc ile açtığımız bellek boyutunu aşıyorsa realloc fonksiyonu ile bufferin
	   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et
	 */

	/* TODO: Eger realloc basarili olduysa ayrılan alanda eski karakterlerin üzerine yazmadan kaldığın
	   bellek alanından okumaya devam et (not:bunun için bellekteki mevcut pozisyonu gösteren bir gösterici tutulabilir)
	 */

   /* TODO: Stringin en sonuna sonlandirma karakterini ekle '\0'
    */

int main(int argc, char *argv[])
{
	char *buffer = my_getline();

	printf("%s\n", buffer);
	return 0;
}
