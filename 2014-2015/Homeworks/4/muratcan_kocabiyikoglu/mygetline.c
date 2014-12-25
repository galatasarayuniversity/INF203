#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	int sayac = 0;

	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer
	 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
	 */
	// buffer =  .... malloc (sizeIncrement);
	buffer = (char *)malloc(sizeIncrement);
	if (buffer != NULL) {
		printf("Basarili\n\n");
	} else {
		printf("Basarisiz\n\n");
	}

	while (1) {
		character = fgetc(stdin);
		/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
		 */
		if (character == '\n') {
			break;
		}

		/*TODO Okunan karakter sayisini arttir ve
		   E�er okunan karakter say�s� malloc ile a�t���m�z bellek boyutunu a��yorsa realloc fonksiyonu ile bufferin
		   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et
		 */

		buffer[sayac] = character;
		sayac++;

		/* TODO: Eger realloc basarili olduysa ayr�lan alanda eski karakterlerin �zerine yazmadan kald���n
		   bellek alan�ndan okumaya devam et (not:bunun i�in bellekteki mevcut pozisyonu g�steren bir g�sterici tutulabilir)
		 */

		if (sayac == sizeIncrement) {
			char *bufferNew = realloc(buffer, sayac + sizeIncrement);
			if (bufferNew == NULL) {
				printf("Basarisiz\n\n");
				free(buffer);
			} else {
				sizeIncrement = sayac + sizeIncrement;
				buffer = bufferNew;
			}
		}

		/* TODO: Stringin en sonuna sonlandirma karakterini ekle '\0'
		 */
		buffer[sayac] += '\0';
	}
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	free(buffer);		// en son belleği boşaltmak için
	return 0;
}
