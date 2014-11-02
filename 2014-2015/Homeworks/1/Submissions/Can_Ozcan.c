#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int sayilar[49]={0};
	int defa[49]={0};
    int hafta,sayi;
	int i,j;
	printf("Kac hafta oldugunu yazin:");
	scanf("%d",&hafta);
	for (j=0;j<hafta;j++){
            for(i=0;i<6;i++){
            do
            {
            sayi=1+rand()%49;
            sayilar[sayi-1]++;
	        }while(sayilar[sayi-1]<2);
			defa[sayi-1]++;
		}
		int sayilar[49]={0};
	}
	int k;
	for (k=0;k<49;k++){
		printf(" %d: %d defa\n",k+1,defa[k]);
	}
	return 0;
}

