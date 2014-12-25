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
};

int main(int argc, char *argv[])
{
	int i;
	int inventory_size = 0;	//Stok listesinin boyutu 
	int max_size = 5;
	struct part *inventory;	// stok listesi: inventory (envanter) 
	struct part *current_part = inventory;	// Stok listesinin en son elemanini gostersin 
	int input;		//Kullanicinin menu icin girdigi degeri tutar 

	inventory = malloc(max_size);

	printf("Enter 0 to terminate, anything else to enter a new part:");
	scanf("%d", &input);

	while (input != 0)	//kullanıcı 0 girene kadar bilgileri alacağız.
	{
		if (inventory_size == max_size) {
			max_size = 2 * max_size;	// liste boyutunu 2 katina cikaralim 
			inventory = realloc(inventory, max_size);	// inventory boyutunu büyüttük.
			current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim  
		};

		Part_create(inventory);	//bilgileri almak için fonksiyonumuzu çağırdık.

		inventory_size++;
		current_part++;
		printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
		scanf("%d", &input);

	}
	printf("Inventory size:%d\n", inventory_size);	//envanterimizin boyutunu ekrana bastırdık.

	for (i = 0; i < inventory_size; i++) {
		printf("Part number: %d\n", (inventory + (i * sizeof(int)))->partNumber);
		printf("Part type: %d\n", (inventory + (i * sizeof(int)))->partType);
	}			//stoktaki ürünlerimizin bilgilerini döngü kullanarak ekrana yazdırdık.
	return 0;
}
