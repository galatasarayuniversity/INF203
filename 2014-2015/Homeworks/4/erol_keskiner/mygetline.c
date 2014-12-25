#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{

	char *buffer;
	int sizeIncrement = 10, i = 0, length = 0;	//  i realloc'un ne zaman çalışacağını haber veren sayac
	char character;
	char *currentPosition;
	buffer = (char *)malloc(sizeIncrement);
	if (buffer == NULL) {
		printf("\nmalloc yeterli alan bulamadi\n");
		return 0;
	}
	while (1) {
		character = fgetc(stdin);
		if (character == '\n') {
			break;
		}
		buffer[length] = character;
		length++;

		i = length / 10;
		if (length >= i * (sizeIncrement)) {
			buffer = (char *)realloc(buffer, sizeIncrement);
		}		// realloc ile en fazla 25 karakterlik yer açabildim. neden daha fazla açamıyorum anlayamadım.
		if (buffer == NULL) {
			printf("\nrealloc yeterli alan bulamadi\n");
			break;
		}
		currentPosition = buffer + length;
		/* 
		   yeni bir cursor yarattım doğru yeri de gösterttim ama nerede kullanacağımı anlayamadım. kod bu haldeyken de buffer başladığı yeri kaybetmeden fonksiyondan return oluyor.
		 */

	}
	buffer[length + 1] = '\0';

	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	free(buffer);
	return 0;
}
