#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
int i,j;
int frekans;
int tablo;

int sayac[50]={0};
int sayisal[1000][6];
srand(time(NULL));

for(i=0; i<1000; i++)
{
for(j=0; j<6; j++)
{
frekans=((rand() %49)+1);
sayisal[i][j]= frekans;
sayac[frekans]++;

}


}	

for(tablo=1; tablo<50; tablo++)
{
printf("%d  %d\n",tablo, sayac[tablo]);
}	

return 0;

}
