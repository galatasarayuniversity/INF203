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
	buffer = (char *)malloc(sizeIncrement);
	if (buffer != NULL) {

		while (1) {
			character = fgetc(stdin);

			if (character == '\n') {
				buffer[sayac + 1] = '\0';
				break;
			}
			if (sayac == sizeIncrement) {
				buffer = (char *)realloc(buffer, sayac + sizeIncrement);
				if (buffer == NULL)
					printf("Error!(realloc)");
				sizeIncrement += sizeIncrement;
			}

			buffer[sayac] = character;
			sayac++;

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
