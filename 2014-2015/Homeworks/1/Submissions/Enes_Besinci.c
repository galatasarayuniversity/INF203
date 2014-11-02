#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	// argc, char*argv[] kodu eklenecek 

	int sayi_kontrol[50]={0}; // Sayi daha önce cikmissa 1, cikmamissa 0 degerini almamizi saglayacak
	int sayi_sayac[100]={0}; //1000 adet tur sonunda hangi sayidan ne kadar ciktigini kaydedecek dizi
	int loto[6]={0}; //1 - 49 arası sayıların konulacağı sayısal loto dizisi
	int i,j,n ; // Döngü sayaclari

	int k;
	int a; //cikan rastgele sayinin diziye aktarilma bicimi

	srand(time(NULL));
	
		for(j=1;j<=1000;j++){

			for(i=0;i<6;i++){
			
				do{
					loto[i]=rand()%49;
					a = loto[i];

				}while(sayi_kontrol[i]==1);

				sayi_kontrol[i]++;
				sayi_sayac[a]++;

			}
			
			//memset(sayi_kontrol, 0, 1000);

			for(n=0;n<50;n++){
				sayi_kontrol[n]=0;
			}


		}

		for(k=1;k<=49;k++){

			printf(" %d    %d \n", k, sayi_sayac[k-1] );
		}

		/* 
		
		MANUEL KONTROL ICIN :
		printf(" %d \n", loto[0]);
		printf(" %d \n", loto[1]);
		printf(" %d \n", loto[2]);
		printf(" %d \n", loto[3]);
		printf(" %d \n", loto[4]);
		printf(" %d \n", loto[5]);

		printf(" --------- \n");

		printf(" 10 sayisinin cikma sayisi %d \n", sayi_sayac[9]); */ 

		return 0;

}
