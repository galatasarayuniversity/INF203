/*
 * Sayisal_Loto.c
 *
 *  Created on: Sep 26, 2014
 *      Author: onur
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6

void loto(int *x);
void star(int a);


int main(void){

	srand(time(0));
	int i,j,lotto[N],toplam = 0;
	int counters[49] = {0};
	double oran;
	for(i = 0 ; i < 1000; i++){
		loto(lotto);
		for(j = 0;j < N;j++){
			counters[lotto[j]-1]++;
		}
	}
	printf("Bin adet sayisal loto oynandi. Istatistikler:\n");
	for(i = 0;i < 49; i++){
		printf("\n%d sayisi %d kere kazandi.",i+1,counters[i]);
		oran = ((double)counters[i]/6000)*100;
		printf("\tOran: %f%%",oran);
		star((int)(oran*10));
		toplam = toplam + counters[i];
	}
		printf("\nToplam cekilis:%d \t\tToplam:100%% Yukaridaki oranlar gercek yildiz sayilari semboliktir.", toplam);
	return 0;
}

void loto(int *x){
	int a,i = 0;
	int control[49] = {0};
	for(i = 0 ;i < N;i++){
		a = (rand() % 49);
		while(control[a] == 1){
		a = (rand() % 49);
		}
		control[a] = 1;
		x[i] = a+1;
	}

}
void star(int a){
	int i;
	for(i = 0;i < a;i++)
		printf("*");
}
