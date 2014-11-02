
#include<stdio.h>

#include<time.h>

#include<stdlib.h>

int main(void)
 {
    srand(time(NULL));

	int a,b,c;

	int sayi [49]={0};      // hangi sayıdan kac tane oldugunu tutan dizi //

	int i=0;
	int j=0;

	for (a=0;a<1000;a++)
	{                                        // 1000 kez işlemi tekrarlayan sayac //
		i=1+rand()%49;

		sayi[i-1]++;

		printf( "%d\t",i );

    for (b=0;b<5;b++)
        {    // 6 sayıyı ureten ve birbirinden farklı olduklarını dogrulayan kısım //

    j=1+rand()%49;

    if(i!=j)

			{
    printf("%d\t",j);
			}
    else
			{
    while(i==j)
    {
    j=1+rand()%49;

    break;
				}
    printf("%d\t",j);
			}
    sayi[j-1]++;
		}

    printf("\n");
	}

	for (c=0;c<49;c++)


    printf("\n %d --> %d kez cekilmistir \n ",c+1,sayi[c]);    // 1000 cekilis sonucu olusan degerleri bastıran kısım //

	return 0;
}

