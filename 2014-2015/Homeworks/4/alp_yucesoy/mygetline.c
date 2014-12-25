#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	int counter = 0;
	int i = 1;
	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer 
	 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
	 */
	buffer = malloc(sizeIncrement);
	if (buffer == NULL) {
		return NULL;
	}
	while (1) {
		character = fgetc(stdin);
		/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
		 */

		if (character == '\n') {
			buffer[counter + 1] = '\0';
			break;
		}
		/*TODO Okunan karakter sayisini arttir ve 
		   Eğer okunan karakter sayısı malloc ile açtığımız bellek boyutunu aşıyorsa realloc fonksiyonu ile bufferin
		   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et 
		 */

		if (counter >= i * sizeIncrement) {
			i++;
			buffer = (char *)realloc(buffer, counter + sizeIncrement);
		}
		buffer[counter] = character;
		counter++;
		/* TODO: Eger realloc basarili olduysa ayrılan alanda eski karakterlerin üzerine yazmadan kaldığın 
		   bellek alanından okumaya devam et (not:bunun için bellekteki mevcut pozisyonu gösteren bir gösterici tutulabilir)
		 */
		if (buffer == NULL) {
			return NULL;
		}

		/* TODO: Stringin en sonuna sonlandirma karakterini ekle '\0'  
		 */

	}
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
