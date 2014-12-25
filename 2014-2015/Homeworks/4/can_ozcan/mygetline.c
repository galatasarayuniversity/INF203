#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	char *currentPozition;	//En sonuncu karakter pointer'ı
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	int sefer = 1;		//Kac kere sizeIncrement oldugunu gösterir
	int length = 0;
	char character;		// Okunan karakter

	buffer = malloc(sizeIncrement);

	while (1) {
		character = fgetc(stdin);
		if (character == '\n') {
			break;
		}

		if (length > sefer * sizeIncrement) {
			sefer++;
			buffer = realloc(buffer, sefer * sizeIncrement);
		}
		currentPozition = buffer + length;
		*(currentPozition) = character;
		length++;

	}
	*(currentPozition + 1) = '\0';
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
