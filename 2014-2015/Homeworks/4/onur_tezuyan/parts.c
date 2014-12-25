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
	int max_size = 5, i;
	struct part *inventory;	// stok listesi: inventory (envanter) 
	struct part *current_part;	// Stok listesinin en son elemanini gostersin 
	int input;		//Kullanicinin menu icin girdigi degeri tutar 

/* TODO: malloc ile max_size boyutunda bir stok listesi - inventory (envanter) olusturalim 
   Kullanıcı yeni stok bilgisi girdikçe stok boyutu artabilir , ilk olarak 5lik (max_size) 
   bir yer ayıralım ve ihtiyaç oldukça alanı genişletelim, yerin ayrilip ayrilmadigini kontrol edelim */
	inventory = malloc(max_size * sizeof(struct part));
	if (inventory == NULL) {
		printf("Error: Malloc");
		return 1;
	}
	current_part = inventory;

//Kullanici 0 girene kadar stok bilgilerini alacagiz 
	printf("Enter 0 to terminate, anything else to enter a new part:");
	scanf("%d", &input);

	while (input != 0) {
		if (inventory_size == max_size) {
			/* TODO: Eger stok boyutunu astiysak, realloc ile liste boyutunu 2 katina cikaralim
			 */

			//inventory = ... 
			max_size = 2 * max_size;	// liste boyutunu 2 katina cikaralim 
			inventory = realloc(inventory, max_size);
			if (inventory == NULL) {
				printf("Error: Malloc");
				return 1;
			}
			current_part = inventory + inventory_size;	//en son elemanin uzerine yazmamak icin adresi guncelleyelim  
		}

		/*TODO: Part_create fonksiyonunu cagirarak yeni stok bilgilerini alalim
		 */
		Part_create(current_part);

		inventory_size++;
		current_part++;
		printf("\n\nEnter 0 to terminate, anything else to enter a new part:");
		scanf("%d", &input);

	}

//print the list 
/*TODO: Envanterin boyutunu basalim 
*/
	printf("Inventory size:%d\n", inventory_size);

/*TODO: Stoktaki urunlerin  bilgilerini bır dongu basalim 
*/
	for (i = 0; i < inventory_size; i++) {
		printf("%d: (%d,%d)\n", i + 1, inventory[i].partNumber, inventory[i].partType);

	}
	return 0;
}
