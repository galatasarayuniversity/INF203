#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;
	char character;
	int sizeIncrement = 10;
	int counter = 0;

	buffer = (char *)malloc(sizeIncrement);
	if (buffer == NULL) {
		printf("Hata var!");
		return NULL;
	}

	while (1) {
		character = fgetc(stdin);
		if (character == '\n') {
			break;
		}

		buffer[counter] = character;
		counter++;
		if (counter >= sizeIncrement) {
			char *temp = realloc(buffer, counter + sizeIncrement);
			if (temp == NULL) {
				printf("Hata var!");
				free(buffer);
				return NULL;
			} else {
				sizeIncrement *= 2;
				buffer = temp;
			}
		}
	}

	buffer[counter] = '\0';
	return buffer;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
