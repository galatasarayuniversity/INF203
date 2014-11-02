#include <stdio.h>
#include <time.h>

int main(){
    int check[1000][49]={0}, loto[1000][6], counter[49]={0},i,j,x;
	srand(time(NULL));
    for(i=0;i<1000;i++){
        for(j=0;j<6;j++){
			x=rand()%49;
         if(check[i][x]==0){
                loto[i][j]=x+1;
                check[i][x]=1;
                counter[x]++;
            } else {
            	j--;
            }          
   	   }
    }
    for(i=0;i<49;i++){
    	printf("%2d: %d\n",i+1 ,counter[i]);
    }
}
