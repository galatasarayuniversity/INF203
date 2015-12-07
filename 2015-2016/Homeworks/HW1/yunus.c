#include <stdio.h>
#include <assert.h>

int r_strchr(char *string, char c) {
	if(*string==c)
		return 1;
	if(*string=='\0')
		return 0;
	int control =r_strchr(string+1,c);
	return control;
}
int r_strlen(char *string) {
	if (*string!='\0') {
		return r_strlen(string + 1) + 1;
	}
	return 0;
}

int r_strcount(char *string, char c) {
	return *string? r_strcount(string+1,c)+(c==*string):0;
}

int roman_digit_to_int(char c) {
	int value=0;
	switch(c){
	case 'I': value = 1; break;
	case 'V': value = 5; break;
	case 'X': value = 10; break;
	case 'L': value = 50; break;
	case 'C': value = 100; break;
	case 'D': value = 500; break;
	case 'M': value = 1000; break;
	case '\0': value = 0; break;
	default: value = 0;
	}
	return value;

}
int roman_number_to_int(char *string) {
	int total=0,i;
	for(i=0;i<7;i++){
		int x=roman_digit_to_int(string[i]);
		int y=roman_digit_to_int(string[i+1]);
		if(x<y)
			total-=x;
		else total+=x;}
	return total;
}
int r_sum_digits(int x) {
	return  x!=0? x%10+r_sum_digits(x/10):0;
}

int main(int argc, char *argv[]) {

	assert(r_strchr("ahmet mehmet\n\n\t", 'h') == 1);
	assert(r_strchr("ahmet", 'x') == 0);
	assert(r_strchr("ahmet", 'a') == 1);
	assert(r_strchr("hhhhhhha", 'x') == 0);
	printf("All tests passed for r_strchr()!\n");

	assert(r_strlen("ahmet mehmet kokokoko\t\t") == 23);
	assert(r_strlen("ahmet") == 5);
	assert(r_strlen("a") == 1);
	assert(r_strlen("") == 0);
	printf("All tests passed for r_strlen()!\n");

	assert(r_strcount("ahmet", 'a') == 1);
	assert(r_strcount("ahmeta", 'a') == 2);
	assert(r_strcount("ahmeta", 'x') == 0);
	assert(r_strcount("", 'x') == 0);
	assert(r_strcount("ahmet mehmet\n\n\t", 't') == 2);
	printf("All tests passed for r_strcount()!\n");

	assert(roman_number_to_int("IIII") == 4);
	assert(roman_number_to_int("IV") == 4);
	assert(roman_number_to_int("VIIII") == 9);
	assert(roman_number_to_int("IX") == 9);
	assert(roman_number_to_int("MIM") == 1999);
	assert(roman_number_to_int("MCMXCIX") == 1999);
	assert(roman_number_to_int("D") == 500);
	printf("All tests passed for roman_number_to_int()!\n");


	assert(r_sum_digits(0) == 0);
	assert(r_sum_digits(9) == 9);
	assert(r_sum_digits(10) == 1);
	assert(r_sum_digits(100) == 1);
	assert(r_sum_digits(1009) == 10);
	assert(r_sum_digits(152101) == 10);
	assert(r_sum_digits(999999) == 54);
	printf("All tests passed for r_sum_digits()!\n");


	return 0;
}
