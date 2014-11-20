
#include <stdio.h>
#include <string.h>
#include "contactlist.c"
#include "contactlist.h"

int main(int argc, char *argv[])
{

	int a;
	struct ContactList list;

	while (1) {

		printf("Telefon Defteri \n ------------ \n [1]: Yeni İsim Ekle\n [2]:Listeyi Bastır\n [3]:Çıkış\n");
		scanf("%d", &a);

		switch (a) {

		case 1:
			insert_new_contact(&list);

		case 2:
			print_contact_list(&list);

		case 3:
			break;
		}

	}

	return 0;
}
