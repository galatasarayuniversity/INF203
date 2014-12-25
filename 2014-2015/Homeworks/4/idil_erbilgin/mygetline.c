
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	int maxlenght;
	int sayac = 0;
	char *current = buffer;	//son elemanı gösteren pointer 

	buffer = (char *)malloc(sizeIncrement);
	if (buffer != NULL) {
		while (1) {
			do {
				character = fgetc(stdin);
				buffer[sayac] = character;
				sayac++;

				if (sayac == sizeIncrement) {
					buffer = (char *)realloc(buffer, sizeIncrement += sizeIncrement);
					if (buffer != NULL) {
						current = buffer + sayac;	//pointerı son pozisyona getirdik

					}
				}
			}
			while (character != '\n');

			buffer[sayac + 1] = '\n';

			/*TODO Okunan karakter sayisini arttir ve
			   EÃ°er okunan karakter sayÃ½sÃ½ malloc ile aÃ§tÃ½Ã°Ã½mÃ½z bellek boyutunu aÃ¾Ã½yorsa realloc fonksiyonu ile bufferin
			   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et
			 */

			/* TODO: Eger realloc basarili olduysa ayrÃ½lan alanda eski karakterlerin Ã¼zerine yazmadan kaldÃ½Ã°Ã½n
			   bellek alanÃ½ndan okumaya devam et (not:bunun iÃ§in bellekteki mevcut pozisyonu gÃ¶steren bir gÃ¶sterici tutulabilir)
			 */

			/* TODO: Stringin en sonuna sonlandirma karakterini ekle '\0'
			 */
		}

		return buffer;
	}
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
