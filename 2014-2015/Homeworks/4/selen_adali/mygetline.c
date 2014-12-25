#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter

	buffer = malloc(sizeIncrement);

	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer
	 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
	 */
	// buffer =  .... malloc (sizeIncrement);
	if (buffer != NULL) {
		int i = 0;
		int say = 0;
		while (character != '\n') {
			character = fgetc(stdin);
			buffer[say] = character;

			if (i == sizeIncrement) {
				buffer = realloc(*buffer, sizeIncrement);

				if (buffer != NULL) {
					return NULL;
				}

			}

			else
				i++;
			say++;

		}
		/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
		 */

		/*TODO Okunan karakter sayisini arttir ve
		   E�er okunan karakter say�s� malloc ile a�t���m�z bellek boyutunu a��yorsa realloc fonksiyonu ile bufferin
		   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et
		 */

		/* TODO: Eger realloc basarili olduysa ayr�lan alanda eski karakterlerin �zerine yazmadan kald���n
		   bellek alan�ndan okumaya devam et (not:bunun i�in bellekteki mevcut pozisyonu g�steren bir g�sterici tutulabilir)
		 */

		/* TODO: Stringin en sonuna sonlandirma karakterini ekle '\0'
		 */

		buffer[say + 1] = '\0';

	} else {
		return NULL;
	}

	return buffer;

}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
