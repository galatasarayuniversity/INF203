#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;		//Kullanicinin girdigi karakterleri kaydedecegimiz buffer pointer
	int sizeIncrement = 10;	// Eger buffer dolduysa her defasinda bu kadarlik bir boyut arttirimi yapacagiz
	char character;
	// Okunan karakter

	int boyut = 0;
	char *son;
	int max;
	buffer = malloc(sizeIncrement);
	if (buffer == NULL) {
		return NULL;
	}
	son = buffer;

	while (1) {
		character = fgetc(stdin);

		if (character == '\n') {
			break;
		}

		if (++boyut >= max) {
			char *yeni = realloc(buffer, max += sizeIncrement);

			if (yeni == NULL) {
				free(buffer);
				return NULL;
			}
			son = yeni + (son - buffer);
			buffer = yeni;
		}

		*son++ = character;

	}
	*son = '\0';
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
