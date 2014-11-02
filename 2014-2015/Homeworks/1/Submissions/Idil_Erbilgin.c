#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
int i,j,a,b;
int loto[1000][6];
int sayac[50]={0};

srand(time(0));

for(i=0; i<1000; i++)
{
for(j=0; j<6; j++)
{
a=1+ rand() %49;
loto[i][j]= a;
sayac[a]++;

}


}	

for(b=0; b<49; b++)
{
printf("%d  %d\n",b+1, sayac[b+1]);
}	













}
