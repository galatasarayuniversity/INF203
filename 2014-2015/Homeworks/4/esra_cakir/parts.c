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
	int k;
	int inventory_size = 0;	//Stok listesinin boyutu 
	int max_size = 5;
	struct part *inventory = malloc(max_size * sizeof(struct part));	// stok listesi: inventory (envanter) 
	struct part *current_part = inventory;	// Stok listesinin en son elemanini gostersin 
	int input;		//Kullanicinin menu icin girdigi degeri tutar 

	if (current_part == NULL) {
		return 1;
	}

	printf("\nEnter 0 to terminate, anything else to enter a new part:");
	scanf("%d", &input);

	while (input != 0) {
		if (inventory_size == max_size) {

			inventory = realloc(inventory, 2 * max_size * sizeof(struct part));
			if (inventory == NULL)
				max_size = 2 * max_size;	// liste boyutunu 2 katina cikaralim 
			current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim  
		}

		Part_create(current_part);
		inventory_size++;
		current_part++;
		printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
		scanf("%d", &input);

	}
	printf("\nInventory size:%d\n\n", current_part - inventory);

	for (k = 0; inventory != current_part; k++) {
		printf("%12d : (%d, %d)\n", k + 1, inventory->partNumber, inventory->partType);
		inventory++;
	}

	return 0;
}
