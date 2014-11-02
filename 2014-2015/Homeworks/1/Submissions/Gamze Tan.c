#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (int argc, char *argv[]) {
	
	int cekilis[1000][6];
	int i,j;
    int sayac[49]={0};
    
    srand(time(NULL));
    
    //Cekilisin yapildigi kisim
	for(i=0;i<1000;i++){
		printf("%d cekilis: \n",i+1);
		
		for(j=0;j<6;j++){
			cekilis[i][j]= 1 + rand()%49;
			
           printf(" %2d \t ",cekilis[i][j]);
           
			sayac[cekilis[i][j]-1]++;
           }
		
	
		printf("\n");
	}
	   //hangi sayidan kac tane geldigini yazan kisim
	   for(i=0;i<49;i++){
	    printf("%2d sayisindan %d adet var.\n", i+1, sayac[i]);	
	}
	
	system("pause");
	return 0;
}
