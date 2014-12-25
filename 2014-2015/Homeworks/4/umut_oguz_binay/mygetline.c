//
//  main.c
//  realloc
//
//  Created by Umut Oğuz Binay on 3.11.2014.
//  Copyright (c) 2014 Umut Oğuz Binay. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_getline(void)
{
	char *buffer;
	int sizeIncrement = 10;
	buffer = malloc(sizeof(char) * sizeIncrement);
	char character;
	printf("karakter giriniz\n");
	scanf("%c", &character);

	while (character != 'n') {
		int sayac = 0;
		int a = 1;
		if (sayac == sizeIncrement * a) {
			sizeIncrement = 2 * sizeIncrement;
			buffer = (char *)realloc(buffer, sizeIncrement * sizeof(char));
			a++;
		} else {
			buffer[sayac] = character;
			sayac++;
			printf("bir karakter giriniz\n");
			scanf("%c", &character);
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char *buffer = my_getline();
	printf("%s\n", buffer);
	return 0;
}
