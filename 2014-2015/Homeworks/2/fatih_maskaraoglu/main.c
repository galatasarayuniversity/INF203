/*
 * main.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactlist.h"
#include "contactlist.c"
#include <unistd.h>
#define kps 20

int main(int argc, char *argv[])
{
	telefon *insanlar;
	insanlar = (telefon *) malloc(sizeof(telefon) * kps);

	char secim;

	printf("[0]yeni bir kisi ekleme \n [1] kisi listesini görüntüleme \n [2] cikis");

	secim = putchar(getchar());

	switch (secim) {
	case '0':
		{
			insertnewcontact(insanlar);
			break;
		}
	case '1':
		print_contact(insanlar);
		break;
	case '2':
		{
			system("pause");
			return 0;
		}
		break;
	}
	return 0;
}
