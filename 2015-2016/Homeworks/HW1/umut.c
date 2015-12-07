#include <stdio.h>
#include <assert.h>

/* Soru 1 */
int r_strchr(char *string, char c) {
    /* TODO */
    int i;
    for (i=0; i<string; i++) {
        if (r_strchr(string,c)!=0) {
            return 0;}
        else{
            return 1;
        }
        
        }
    }
}

/* Soru 2 */
int r_strlen(char *string) {
    /* TODO */
    if (*string=='\0'){
        return 0;
    }
        else
        return (1+r_strlen(string+1));
}

/* Soru 3 */
int r_strcount(char *string, char c) {
    /* TODO */
    if (*string=='\0') {
        return 0;
    }
    else
        return r_strcount(string+1,c);
}

/* Soru 4 Yardimci fonksiyon */
int roman_digit_to_int(char c) {
    /* TODO */
    switch(c){
        case 'I': value = 1; break;
        case 'V': value = 5; break;
        case 'X': value = 10; break;
        case 'L': value = 50; break;
        case 'C': value = 100; break;
        case 'D': value = 500; break;
        case 'M': value = 1000; break;
        case '\0': value = 0; break;
        default: value = -1;
    }
    
    return value;
}

/* Soru 4 Esas fonksiyon */
int roman_number_to_int(char *string) {
    /* TODO */
    int i=0;
    int number=0;
    int boyut = r_strlen(*string);
    for (i=0; i<boyut; i++) {
        if (boyut==1) {
            return roman_number_to_int(string);
        }
        if (boyut>=2) {
            if (roman_number_to_int(string[i]>=roman_number_to_int(string[i+1]))) {
                return roman_number_to_int(string[i]);
            }
            else roman_number_to_int(string[i+1]) - roman_number_to_int(string[i]);
            i++;
        }
    }
  
}

int r_sum_digits(int x) {
    /* TODO */
    int value=0;
    if (x<10) {
        return x
    }
    else
        return value=r_sum_digits(x/10)+(x%10);
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
