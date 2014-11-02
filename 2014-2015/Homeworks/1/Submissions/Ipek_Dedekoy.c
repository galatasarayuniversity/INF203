#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

int i,j;
int a,n;
int dizi[1000][6];
int k;
int dizi2[6];
int sayac[49]={0};
srand(time(NULL));
for(i=0;i<=1000; i++)
{ 
    
    for(j=0; j<6; j++){
	dizi2[j]=rand() %50;
         
        for (n=0;n<j;n++){
          if (dizi2[j]==dizi2[n]){
               dizi2[j]=rand()%50;
         
               break;
            }
			
			dizi[i][j]= dizi2[j];
			}
	a=dizi2[j];
	sayac[a]++;
}
			}
for(i=0; i<49; i++) {

printf("\n %d.sayi=%d\n", i+1, sayac[i]);

}

system("PAUSE");
}

