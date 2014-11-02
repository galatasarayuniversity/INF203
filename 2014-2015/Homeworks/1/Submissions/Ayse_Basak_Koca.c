#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000
#define S 6

int main(){
	
	srand(time(NULL));
	int cekilis[N][S];
	int a[49]={0};
	int i,j,k,x;
	for(i=0; i<1000; i++){
		for(j=0; j<6; j++){
			cekilis[i][j]=1+(rand()%49);
			for(k=1; k<50; k++){
				if(cekilis[i][j]==k){
					a[k-1]+=1;
				}
			}
		}
	}
	for(x=0; x<49; x++){
		printf("%d\t %d\n", x+1, a[x]);
	}
getchar();
return 0;
}
