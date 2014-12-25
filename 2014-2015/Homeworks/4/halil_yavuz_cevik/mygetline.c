
/*
 * main.c
 *
 *  Created on: Nov 2, 2014
 *      Author: yc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int counter = 0;
	int sizeincrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter

	// karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	buffer = (char *)malloc(sizeincrement);

	int flag = 0;

	if (buffer == NULL) {

		printf("Buffer icin yer ayrılmada hata\n");
	}

	else {

		while (1) {

			character = fgetc(stdin);

			if (counter != 0 && counter % sizeincrement == 0) {
				/*TODO ve
				   Eðer okunan karakter sayisi malloc ile actigimiz bellek boyutunu asiyorsa realloc fonksiyonu ile bufferin
				   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et.
				   Bu noktada counter
				 */

				/*Asagidaki realloc fonksiyonunda ; counter 10 ve 10'un katlarinda oldugunda, counter kadar bellek artırımı yapılcagi icin her seferinde
				 * sizeincrement kadar arttirim yapilacaktir
				 */

				buffer = (char *)realloc(buffer, (sizeincrement + counter));

				if (buffer == NULL) {

					printf("Buffer icin yeni bellek ayrılmada hata\n");

					flag = 1;
				}
			}

			if (flag == 0)
				/*Eger realloc basarili olduysa ayrýlan alanda eski karakterlerin üzerine yazmadan kaldýðýn
				   bellek alanýndan okumaya devam et */

			{

				if (character != '\n') {

					*(buffer + counter) = character;

					//Okunan karakter sayisini arttir

					counter++;
				}

				if (character == '\n') {
					//Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirildi.
					*(buffer + counter + 1) = '\0';
					//Stringin en sonuna sonlandirma karakterini ekle '\0'

					break;

				}
			}
		}
	}
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
