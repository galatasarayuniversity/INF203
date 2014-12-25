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
	struct part *inventory;	//Stok listesi: inventory (envanter)
	struct part *current_part = inventory;	//Stok listesinin en son elemanini gostersin
	int input;		//Kullanicinin menu icin girdigi degeri tutar
	int i;

	//malloc ile max_size boyutunda bir inventory olusturduk
	inventory = (struct part *)malloc(max_size);

	//Kullanici 0 girene kadar stok bilgilerini alacagiz
	printf("Enter 0 to terminate,anything else to enter new part:");
	scanf("%d", &input);

	while (input != 0) {
		if (inventory_size == max_size) {
			//stok boyutu asilirsa,realloc ile listeboyutu 2 katina cikartilmali
			max_size = 2 * max_size;	//liste boyutunu 2 katina cikaralim
			inventory = (struct part *)realloc(inventory, max_size);

			current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim

		}
		//Part_create fonksiyonu ile yeni stok alma
		Part_create(current_part);

		inventory_size++;
		current_part++;
		printf("\n\nEnter 0 to terminate,anything else to enter a new part:");
		scanf("%d", &input);
	}
	//print the list
	//Envanterin boyutunu basalim
	printf("Inventory size:%d\n", inventory_size);

	//stoktaki urunlerin bilgilerini bastirma
	for (i = 0; i < inventory_size; i++) {
		printf("%d. Part number : %d \n", i + 1, inventory[i].partNumber);
		printf("%d. Part Type : %d\n", i + 1, inventory[i].partType);
	}
	return 0;
}
