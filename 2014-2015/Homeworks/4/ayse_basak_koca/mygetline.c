#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{

	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;		// Okunan karakter
	char *ilkson = buffer;	// buffer boyutunu artırmamız durumunda kaldığımız yerden devam edebilmemiz için son elemanı gösterir.
	int sayac = 0;

	buffer = malloc(sizeIncrement);
	if (buffer != NULL) {
		while (1) {
			do {
				character = fgetc(stdin);
				buffer[sayac] = character;
				sayac++;
				if (sayac == sizeIncrement) {
					buffer = realloc(buffer, sizeIncrement += sizeIncrement);
					if (buffer != NULL) {
						ilkson = buffer + sayac;
					}

				}

			}
			while (character = '\n');
			buffer[sayac] = '\0';	//stringe son karakteri ekliyoruz
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
