#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  NOT: ENTER ASCII GİRİŞİNİ GERÇEKLEŞTİREMEDİĞİM İÇİN 'ENTER' YERİNE ' . ' KULLANDIM.

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	int i = 0, length = 0;

	buffer = (char *)malloc(sizeIncrement);	/* TODO: karakterleri icine kaydedecegimiz buffer icin malloc() ile yer ayiralim.
						 * Her defasinda buffer boyutunu sizeIncrement kadar arttiracagiz, ilk yer 
						 ayirdigimizda da sizeIncrement kadar ayiralim, yer ayrilip ayrilmadigini kontrol edelim
						 */
	if (buffer != NULL) {
		//Başarılı
		length = sizeIncrement;
	} else {
		//Başarısız
		printf("Malloc Başarısız");
	}
	// buffer =  .... malloc (sizeIncrement);

	while (1) {
		character = fgetc(stdin);
		/* TODO: Kullanici enter tusuna basana kadar karakter okumaya devam edelim, eger enter girildi ise dongu kirilmali
		 */
		if (character != 46) {
			if (i + 1 <= length) {
				buffer[i] = character;
				i++;

			} else {
				buffer = (char *)realloc(buffer, sizeIncrement);
				if (buffer != NULL) {
					//Başarılı
					length = length + sizeIncrement;
				} else {
					//Başarısız
					printf("Realloc başarısız");
				}
			}
		} else {
			if (i + 1 <= length) {
				buffer[i] = '\0';
				break;
			} else {
				buffer = (char *)realloc(buffer, 1);
				if (buffer != NULL) {
					//Başarılı
					buffer[i + 1] = '\0';
				} else {
					//Başarısız
					printf("Realloc başarısız");
				}
				break;
			}
		}
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
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
