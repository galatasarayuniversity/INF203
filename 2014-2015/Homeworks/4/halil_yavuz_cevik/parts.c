
/*
 * parts.c
 *
 *  Created on: Nov 3, 2014
 *      Author: yc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct part {
	int partNumber;
	int partType;
};

void Part_create(struct part *part)
{
	printf("Enter part number:");
	scanf("%d", &(part->partNumber));
	printf("Enter part type:");
	scanf("%d", &(part->partType));
}

int main(int argc, char *argv[])
{
	int inventory_size = 0;	//Stok listesinin boyutu
	int max_size = 5;
	int part_counter = 0;	// Envanterdeki eleman sayisini tutacak
	int i;			//Ekrana bastirma dongusunde kullanacagiz
	struct part *inventory;	// stok listesi: inventory (envanter)
	struct part *current_part = inventory;	// Stok listesinin en son elemanini gostersin
	int input;		//Kullanicinin menu icin girdigi degeri tutar

	//malloc ile max_size boyutunda bir stok listesi - inventory (envanter) olusturduk

	inventory = (struct part *)malloc(max_size);

	if (inventory == NULL) {
//Yerin ayrilip ayrilmadigi kontrol ediliyor
		printf("Malloc ile bellek ayirma islemi basarisiz\n");

	} else {

//Kullanici 0 girene kadar stok bilgilerini alacagiz

		printf("Enter 0 to terminate, anything else to enter a new part:");
		scanf("%d", &input);

		while (input != 0) {
			if (inventory_size == max_size) {

//Eger stok boyutunu astiysak, realloc ile liste boyutunu 2 katina cikaralim

				max_size = 2 * max_size;
				current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim
				inventory = (struct part *)realloc(inventory, max_size);	// liste boyutunu 2 katina cikaralim

				if (inventory == NULL) {

					printf("Realloc ile yeniden bellek ayirma islemi basarisiz\n");

					break;
				}

			}
//Part_create fonksiyonunu cagirarak yeni stok bilgilerini alalim

			Part_create(current_part);

			inventory[part_counter] = *current_part;
			part_counter++;
			inventory_size++;
			current_part++;
			printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
			scanf("%d", &input);

		}

//Envanterin boyutunu basalim

		printf("Inventory size:%d\n", inventory_size);

		//Stoktaki urunlerin  bilgilerini býr dongu basalim

		for (i = 0; i < part_counter; i++) {

			printf("Part Number : %d    Part Type : %d \n", inventory[i].partNumber, inventory[i].partType);

		}

	}
	return 0;

}
