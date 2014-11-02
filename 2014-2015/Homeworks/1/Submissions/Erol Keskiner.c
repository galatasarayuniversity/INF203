#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(int argc, char * argv[]) {
	srand((unsigned) time(0));
	int binlik[1000][6] = { 0 };
	int a, i, j = 0, x;
	int tahmin[6] = { 0 }, frekans[49] = { 0 };
	
	//cekilislerin kayıtları	
	for (a = 0; a < 1000; a++) {
		
		//her bir cekiliste rastgele 6 sayı atama
		for (i = 0; i <= 5; i++) {
			tahmin[i] = 1 + rand() % 49;
	
			// bir cekiliste aynı sayı olmaması kontrolu	
			for (j = 0; j < i; j++) {
												
				while (tahmin[i] == tahmin[j]) {
					tahmin[i] = 1 + rand() % 49;
				}
			
			}
			
			binlik[a][i] = tahmin[i];    
			x = tahmin[i];
			//her sayının ne kadar cıktıgını kaydeden dizi(her sayı kendinden bir eksik sayılı indiste tutuluyor)
			frekans[x - 1] += 1;
		
		}
	}
	
	for (i = 0; i < 49; i++) {
	
		printf("%2d %5d\n", i + 1, frekans[i]);
	
	}

	return 0;

}

