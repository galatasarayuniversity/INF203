/*
 * alistirma1.c
 *
 *  Created on: 15 Kas 2015
 *      Author: canozcan
 */
#include <stdio.h>
#include <string.h>
int r_strchr(char *string,char c){
	if(string!=NULL || *string!='c'){
		return r_strchr(string+1,c);
	}
	else if(*string=='c'){
		return 1;
	}
	else{
		return 0;
	}
}

/*
 * alistirma2.c
 *
 *  Created on: 15 Kas 2015
 *      Author: canozcan
 */
#include <stdio.h>
#include <string.h>
int r_strlen(char *string){
	if(string==NULL){
		return 0;
	}
	else{
		return r_strlen(string+1)+1;
	}
}

/*
 * alistirma3.c
 *
 *  Created on: 15 Kas 2015
 *      Author: canozcan
 */
#include <stdio.h>
#include <string.h>

int r_strcount(char *string,char c){
	if(string!=NULL|| *string!='c'){
		return r_strcount(string+1,c);
	}
	else if(*string=='c'){
		return r_strcount(string+1,c)+1;
	}
	else{
		return 0;
	}
}
/*
 * alistirma5.c
 *
 *  Created on: 15 Kas 2015
 *      Author: canozcan
 */
#include <stdio.h>
#include <string.h>
int r_sum_digits(int x){
	if(!(x/10)){
		return x;
	}
	else{
		return r_sum_digits(x/10)+x%10;
	}
}


int main(void){
	int a;
	printf("sayiyi girin:\n");
	scanf("%d",&a);
	printf("sonuc:%d",r_sum_digits(a));
	return 0;
}

