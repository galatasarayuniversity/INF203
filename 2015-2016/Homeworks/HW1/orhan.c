#include <stdio.h>
#include <assert.h>

/* Soru 1 */
int r_strchr(char *string, char c) {
	
	if(*string == c)
		return 1;
	else if(*string == '\0')
		return 0;
	else 
		return r_strchr(string+1,c);
		
}

/* Soru 2 */
int r_strlen(char *string) {
    
	if(*string == '\0')
		return 0;
	else if(*string == '\\')
		return 1+r_strlen(string+2);
	else
		return 1+r_strlen(string+1);
}


/* Soru 3 */
int r_strcount(char *string, char c) {
       
	if(*string == '\0')
		return 0;
	else if(*string != c)
		return r_strcount(string+1,c);
	else
		return 1+r_strcount(string+1,c);
	
} 


/* Soru 4 Yardimci fonksiyon */
int roman_digit_to_int(char c) {
    
    if(c == 'M')
    	return 1000;
    else if(c == 'D') 
    	return 500;
    else if(c == 'C')
    	return 100;
    else if(c == 'L')
    	return 50;
    else if(c == 'X')
    	return 10;
    else if(c == 'V')
    	return 5;
    else if(c == 'I')
    	return 1;
    
}

/* Soru 4 Esas fonksiyon */

int roman_number_to_int(char *string) {
    
	if(r_strlen(string) == 1)
    		return roman_digit_to_int(*string);
	else{
		if(roman_digit_to_int(*string) >= roman_digit_to_int(*(string+1)))
			return roman_digit_to_int(*string) + roman_number_to_int(string+1);
		else
			return -roman_digit_to_int(*string) + roman_number_to_int(string+1); 
	}
}

int r_sum_digits(int x) {

	if(x==0)
		return 0;
	else
		return (x%10) + r_sum_digits(x/10);    
}
int main(int argc, char *argv[]) {
    /* NOTE: Test kodu, buraya dokunmayin! */

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
