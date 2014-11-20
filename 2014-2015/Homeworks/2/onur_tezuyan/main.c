/*
 * main.c
 *
 *  Created on: Oct 19, 2014
 *      Author: onur
 */
#include <stdio.h>
#include "contactlist.h"

int main(void)
{

	struct ContactList cl;
	int a = 0;
	cl.sayac = 0;
	do {
		menu();
		scanf("%d", &a);
		switch (a) {
		case 0:
			if (cl.sayac >= N)
				printf("Defter Dolu!!!\n");
			else {
				insert_new_contact(&cl);
				cl.sayac++;
			}
			break;
		case 1:
			if (cl.sayac > 0)
				print_contact_list(&cl);
			else
				printf("Defter Bos!!!\n");
			break;
		case 2:
			printf("Cikis yapildi");
			return 0;
		default:
			printf("Lutfen gecerli bir sayi giriniz\n");
			break;
		}
	} while (a != 2);

	return 0;
}
