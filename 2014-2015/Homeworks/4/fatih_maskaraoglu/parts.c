/*
 * parts.c
 *
 *  Created on: 3 Kas 2014
 *      Author: fatih
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
	struct part *inventory = malloc(sizeof(char) * max_size);
// stok listesi: inventory (envanter)

	struct part *current_part = inventory;	// Stok listesinin en son elemanini gostersin
	int input;		//Kullanicinin menu icin girdigi degeri tutar

/* TODO: malloc ile max_size boyutunda bir stok listesi - inventory (envanter) olusturalim
   Kullanıcı yeni stok bilgisi girdikçe stok boyutu artabilir , ilk olarak 5lik (max_size)
   bir yer ayıralım ve ihtiyaç oldukça alanı genişletelim, yerin ayrilip ayrilmadigini kontrol edelim */
// struct part *inventory = ...

//Kullanici 0 girene kadar stok bilgilerini alacagiz

	printf("Enter 0 to terminate, anything else to enter a new part:");
	scanf("%d", &input);
	while (input != 0) {
		if (inventory_size == max_size) {
			inventory = realloc(inventory, max_size * 2);
			max_size = 2 * max_size;

			inventory_size = inventory_size + max_size;
			current_part = inventory + inventory_size;

			/* TODO: Eger stok boyutunu astiysak, realloc ile liste boyutunu 2 katina cikaralim
			 */
			//inventory = ...
			// liste boyutunu 2 katina cikaralim
			//en son elemanin uzerine yazmamak icin adresi guncelleyelim
		} else {

			struct part new;
			char *ptr1 = &new;
			Part_create(ptr1);

			/*TODO: Part_create fonksiyonunu cagirarak yeni stok bilgilerini alalim
			 */
			//Part_create(...);
			inventory_size++;
			current_part++;

			printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
			scanf("%d", &input);
		}

	}

	printf("Envanterin boyutu:%d \n", inventory_size);

	int i;
	for (i = 0; i < inventory_size; i++) {
		printf("%d\n%d", inventory[i].partNumber, inventory[i].partType);
	}
//print the list
/*TODO: Envanterin boyutunu basalim
*/
//printf("Inventory size:%d\n", ...);

/*TODO: Stoktaki urunlerin  bilgilerini bır dongu basalim
*/
	return 0;
}
