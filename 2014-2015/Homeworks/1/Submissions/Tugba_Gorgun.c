/*
 * dene.c
 *
 *  Created on: 08 Eki 2014
 *      Author: tugbagorgun
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*1000 cekilisli sayisal loto programi*/
int main(void)
{
	int i, j = 0;
	int kura_sayisi = 1000;
	int max_sayi = 49;
	int loto[49];
/*ayrilan dizini bosalma*/
	for(i = 0; i< 49; i++)
	{
		loto[i]= 0;
	}
/*rastgele sayi belirleme*/
	srand( time( NULL) );

   int temp_counter = 0;

   for(i = 0; i < kura_sayisi; i++)
   {
	   int haftalik[6] = {0};
	   for(j = 0 ; j < 6 ; j++ )
	   {
			haftalik[j] = (rand() % 49) + 1;
/*rastgele gelen sayilarin ayni olup olmadiginin kontrolu*/
			sayi_kontrol:
				temp_counter=0;
			for(temp_counter = 0; temp_counter < j; temp_counter++)
			{
				if(haftalik[temp_counter] == haftalik[j])
				{
					haftalik[j] = (rand() % 49) + 1;
					goto sayi_kontrol;
				}
			}
	   }
	   int m = 0;

	   for(m = 0;m <6 ; m++)
	   {
	   	loto[haftalik[m]-1]++;
	   }
   }

   int total = 0;

   for(j=0; j<49;j++)
   {
   	printf("%d: %d \n",j+1, loto[j]);
   	total += loto[j];
   }
   printf("Total: %d", total);
}
