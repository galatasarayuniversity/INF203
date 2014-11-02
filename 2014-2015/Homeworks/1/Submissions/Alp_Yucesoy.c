#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int a,i;
	int c[6000];
	int b[50] = {0,};
	
	srand(time(NULL));
	
	for(i=0;i<6000;i++){
		a = rand()%50;
		c[i] = a;
		if(i % 6 == 0){
			if( a == c[i-1] || a == c[i-2] || a == c[i-3] || a == c[i-4] || a == c[i-5] || a == c[i-6]){
				i = i-1;
				continue;
			}
		}
		b[a]++;
	}
	for(i=0; i<50; i++)
		printf("%d : %d \n", i + 1, b[i]);
	return 0;
}
