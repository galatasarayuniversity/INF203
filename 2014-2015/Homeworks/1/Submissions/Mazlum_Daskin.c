#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int loto[49] = { 0 }; //matris
	int Sonuc[49] = { 0 }; // kontrol matrisi
	int sayi, i,j;
	srand(time(NULL));
	//printf("Sayisal Loto 6/49\n");
	for (j= 0; j < 1000; j++){

		for (i = 1; i < 7; i++) {

			sayi = 1 + rand() % 49;
			if(loto[sayi - 1] == 1) {  //aynı sayıyı kontrol işlemi
				sayi = 1 + rand() % 49;
			}
			else loto[sayi-1]=1;
			//printf("%d ", sayi);  Kontrol işlemi için kullandım.
			Sonuc[sayi-1]++;


		}
		int loto[49]={0};
		printf("\n");
	}
	int k;
	for (k= 0; k< 49; ++k){
		printf(" %d",k);
		printf(" %d",Sonuc[k]);
		printf("\n");
	}
	return 0;
}

