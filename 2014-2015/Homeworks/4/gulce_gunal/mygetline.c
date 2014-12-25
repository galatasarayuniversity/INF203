#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	int counter = 0;
	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer 
	 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
	 */
	// buffer =  .... malloc (sizeIncrement);
	buffer = malloc(sizeIncrement * sizeof(char));
	if (buffer == NULL) {
		return NULL;
	} else {

		while (1) {
			character = fgetc(stdin);
			/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
			 */

			if (character == '\n')
				break;

			/*TODO Okunan karakter sayisini arttir ve 
			   E�er okunan karakter say�s� malloc ile a�t���m�z bellek boyutunu aşıyorsa realloc fonksiyonu ile bufferin
			   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et 
			 */
			counter++;
			if (counter >= sizeIncrement) {

				char *temp = realloc(temp, (counter + sizeIncrement));
				if (temp == NULL) {
					return NULL;
				} else
					buffer = temp;

				sizeIncrement = counter + sizeIncrement;
			}
			buffer[counter - 1] = character;
			buffer[counter] = '\0';

			/* TODO: Eger realloc basarili olduysa ayrılan alanda eski karakterlerin �zerine yazmadan kald���n
			   bellek alan�ndan okumaya devam et (not:bunun için bellekteki mevcut pozisyonu gosteren bir gosterici tutulabilir)
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
