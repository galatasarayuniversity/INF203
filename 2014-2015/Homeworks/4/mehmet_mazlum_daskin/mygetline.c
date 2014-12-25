#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;
	char *kont;

	int sayi = 0;

	buffer = malloc(sizeof(sizeIncrement));

	if (buffer != 0) {
		printf("islem basarili");
	}

	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
	 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer 
	 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
	 */
	// buffer =  .... malloc (sizeIncrement);

	while (1) {
		character = fgetc(stdin);
		/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
		 */
		if (character != '\0') {
			printf("isslem basarili");
			break;
		}

		sayi++;

		if (sizeof(*buffer) != sizeof(sayi)) {

			buffer = realloc(buffer, sizeof(sizeIncrement + sayi * sizeIncrement));

			if (buffer != 0) {
				printf("islem bsarili");
			}
		}
		/*TODO Okunan karakter sayisini arttir ve 
		   E�er okunan karakter say�s� malloc ile a�t���m�z bellek boyutunu a��yorsa realloc fonksiyonu ile bufferin
		   boyutunu sizeIncrement kadar arttir ve islemin basarili olup olmadigini kontrol et 
		 */
		kont = buffer;
		buffer = kont + sayi;

		/* TODO: Eger realloc basarili olduysa ayr�lan alanda eski karakterlerin �zerine yazmadan kald���n 
		   bellek alan�ndan okumaya devam et (not:bunun i�in bellekteki mevcut pozisyonu g�steren bir g�sterici tutulabilir)
		 */
		buffer = strcpy(buffer, "\0");
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
