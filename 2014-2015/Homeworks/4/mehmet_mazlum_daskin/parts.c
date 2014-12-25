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
	struct part *inventory;	// stok listesi: inventory (envanter) 
	// Stok listesinin en son elemanini gostersin
	int input;		//Kullanicinin menu icin girdigi degeri tutar 
	struct part *current_part = inventory;
	inventory = malloc(sizeof(max_size));
	if (inventory != 0) {
		printf("islem basarili");
	} else
		printf("islem basarisiz");

/* TODO: malloc ile max_size boyutunda bir stok listesi - inventory (envanter) olusturalim 
   Kullan�c� yeni stok bilgisi girdik�e stok boyutu artabilir , ilk olarak 5lik (max_size) 
   bir yer ay�ral�m ve ihtiya� olduk�a alan� geni�letelim, yerin ayrilip ayrilmadigini kontrol edelim */
// struct part *inventory = ... 

//Kullanici 0 girene kadar stok bilgilerini alacagiz 
	printf("Enter 0 to terminate, anything else to enter a new part:");
	scanf("%d", &input);
	inventory_size++;

	while (input != 0) {
		if (inventory_size == max_size) {
			if (sizeof(*inventory) >= sizeof(inventory_size)) {
				printf("islem basaril\n");
			} else
				inventory = realloc(inventory, 2 * inventory_size);

			/* TODO: Eger stok boyutunu astiysak, realloc ile liste boyutunu 2 katina cikaralim
			 */

			max_size = 2 * max_size;	// liste boyutunu 2 katina cikaralim 

			current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim  
		}

		/*TODO: Part_create fonksiyonunu cagirarak yeni stok bilgilerini alalim
		 */
		//Part_create(...); 
		Part_create(inventory);

		inventory_size++;
		current_part++;
		printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
		scanf("%d", &input);

	}

//print the list 
/*TODO: Envanterin boyutunu basalim 
 *
*/
	printf("Inventory size: %d \n", sizeof(inventory));

	int i;
	for (i = 0; i < inventory_size; i++) {
		printf("%d\n", inventory->partNumber);
		printf("%d\n", inventory->partType);

	}

	return 0;
}
