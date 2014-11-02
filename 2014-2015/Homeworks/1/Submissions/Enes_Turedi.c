/*
 * odev01_Enes_Turedi.c
 *
 *  Created on: 2 Eki 2014
 *      Author: packardbeell
 */

#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main(int argc , char* argv[]){
	int z=1;
	int i;
	int str[50]={0};/*sayının çekilişlerde kaç kez çıktığını saklayacak dizi*/


	srand(time(NULL));

	int dizi[6]={60,61,62,63,64,65};/*piyango sonucu tutan dizi*/
	int j,k;


		for(k=0;k<1000;k++)
		{
				for(j=0;j<6;j++){
				ayni_sayi:
				dizi[j]=rand()%49+1;

				if((dizi[0]==dizi[1])||(dizi[0]==dizi[2])||(dizi[0]==dizi[3])||(dizi[0]==dizi[4])||(dizi[0]==dizi[5])
						||(dizi[1]==dizi[2])||(dizi[1]==dizi[3])||(dizi[1]==dizi[4])||(dizi[1]==dizi[5])
						||(dizi[2]==dizi[3])||(dizi[2]==dizi[4])||(dizi[2]==dizi[5])
						||(dizi[3]==dizi[4])||(dizi[3]==dizi[5])
						||(dizi[4]==dizi[5]))
						{goto ayni_sayi;}
				int a;
				a=dizi[j];
				str[a]++;

				printf("%d \n",dizi[j]);
				}


		printf("Çekiliş Sonu:\t %d. çekiliş\n",z);
				z++;
		}
		printf("\n");

		for(i=1;i<50;i++){

			printf("%d:\t  %d\n",i,str[i]);

		}



return 0;

}

