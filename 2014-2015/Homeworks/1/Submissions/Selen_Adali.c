/*
 * Odev01_Selen_Adali.c
 *
 *  Created on: 2 Eki 2014
 *      Author: selen
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void) {
	int j,i,k;
	int dizi[49]={0}; //Her sayının kaç defa çıktığını tutacak sayaçlar
	int a=0;
	int b=0;

	srand(time(NULL));
	for (i=0;i<1000;i++) {
		a=1+rand()%49;
		dizi[a-1]++;
		//printf( "%d\t",a );
		for (j=0;j<5;j++) {
			b=1+rand()%49;
			if(a!=b)     // eşit olmama durumunun kontrolü
			{//printf("%d\t",b);
			}
			else
			{
				while(a==b) {
				b=1+rand()%49;
				break;
				}
				//printf("%d\t",b);
			}
		dizi[b-1]++;
		}
		//printf("\n");
	}
	for (k=0;k<49;k++)
		printf("\n %d sayisi 1000 cekilis sonunda %d kez cikmistir.\n ",k+1,dizi[k]);

	//Yorum satırları da koda dahil edilince tüm çekilişlerin tek tek sonuçları da ekrana basılıyor.
	return 0;
}

