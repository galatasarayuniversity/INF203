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

	buffer = malloc(sizeIncrement);
	if (buffer == NULL) {	//malloc fonksiyonunu kontrol eder
		printf("malloc failed\n");
		return NULL;
	}

	while (1) {
		character = fgetc(stdin);

		if (character == '\n') {
			buffer[counter + 1] = '\0';
			break;
		}

		if (counter >= i * sizeIncrement) {
			i++;
			buffer = (char *)realloc(buffer, i * sizeIncrement);
		}

		buffer[counter] = character;
		counter++;

		if (buffer == NULL) {
			return NULL;
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
