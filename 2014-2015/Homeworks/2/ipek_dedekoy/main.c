
int main(int argc, char *argv[])
{

	char secim = '0';

	printf("---------- \n");
	printf(" Contact List \n");
	printf("* 1.Insert New Contact *\n");
	printf("* 2. Print Contact List *\n");
	printf("* 3. Exit*\n");
	printf("*-------------- *\n");

	do {

		printf("");

		switch (secim) {
		case '1':
			insert_new_contact();
			break;

		case '2':

			print_contact_list();
			break;

		case '3':

			return 0;
			break;

		default:
			printf(" 1ile 3 arasında bir sayi gir");
		}

		return 0;

	} while (secim != 3);

}
