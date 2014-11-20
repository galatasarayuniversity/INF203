#include <stdio.h>
#include <contaclist.h>
#include <contaclist.c>

int main(int argc, char *argv[])
{

	int i = 0, a = 0;
	contact contact[19];
	Contactlist ContactList;

	FILE *clPtr;
	clPtr = fopen("defter.txt", "a+");

	if (clptr == NULL) {
		perror("Error opening file");
	} else if (fgets(struct ContactList, clPtr) != NULL) {

		while (menu != 2) {
			printf("/nContact Listn------------/n[0] : Insert new contact/n[1] : Print contact list/n[2] : Exit ");
			scanf("%d", &menu);
			if (menu == 0) {
				insert_new_contact(*ContactList);
			} else if (menu == 1) {
				print_contact_list(*ContactList);
			} else if (menu == 2) {
				break;
			} else if (menu > 2 || menu < 0) {
				printf("/nHatalı bir tuşa bastınız.Lütfen tekrar deneyiniz");
			}
		}
	}
	fclose(clPtr);
	return 0;
}
