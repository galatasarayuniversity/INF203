/*
 * main.c
 *
 *  Created on: 29 Eki 2014
 *      Author: tugbagorgun
 */

#include <stdio.h>
#include <stdlib.h>
#include "contactlist.h"

void print_menu()
{
	printf("\n[0]:  Insert New Contact");
	printf("\n[1]:  Print Contact List");
	printf("\n[2]:  Exit");
	printf("\nPlease type your selection: ");
}

int main(int argc, char *argv[])
{

	myContactList.BookIndex = 0;
	int i = 0;

	print_menu();
	while (1) {
		int selection = 0;
		scanf("%d", &selection);
		switch (selection) {
		case 0:
			insert_new_contact(&myContactList);
			print_menu();
			break;
		case 1:
			print_contact_list(&myContactList);
			print_menu();
			break;
		case 2:
			return 0;
			break;
		default:
			printf("\nPlease enter a valid selection!");
			print_menu();
			break;
		}
	}
	return 0;
}
