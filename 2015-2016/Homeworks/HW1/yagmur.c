#include <stdio.h>
#include <assert.h>


//YA YİNE ÇEKİRDEK DÖKÜLDÜÜÜ


/* Soru 1 */
int r_strchr(char *string, char c) 
{
    int i = 1;
        
    while (*string)
        if(*string == c)
            return 1;
        else {   
            i++;
            return r_strchr(string + i, c);
        }    
            
    return 0;        
}

/* Soru 2 */
int r_strlen(char *string) 
{
    
    while (*string) {
        return 1 + r_strlen(string + 1);
    }    
    
            
}

/* Soru 3 */
int r_strcount(char *string, char c)
{
     while (*string) { 
        if (*string == c)
             return 1 + r_strcount(string + 1, c);  
        return r_strcount(string + 1, c); 
    } 

}

/* Soru 4 Yardimci fonksiyon */
int roman_digit_to_int(char c) 
{
    switch (c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
    }    

}



/* Soru 4 Esas fonksiyon */
int roman_number_to_int(char *string) 
{
    while (*string) {
        if (r_strlen(string) == 1)
            return roman_digit_to_int(*string); 
        else if (*string >= *(string + 1))
            return roman_digit_to_int(*string) + roman_number_to_int(string + 1);          
        else
            return roman_number_to_int(string + 1) - roman_digit_to_int(*string); 
                          
    } 
            
}

int r_sum_digits(int x) 
{
    int sum;
    
    while (x)
        return x % 10 + r_sum_digits(x / 10);  
    return 0;       
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
    assert(roman_number_to_int("MCMI") == 1901); 
    assert(roman_number_to_int("MCMX") == 1910); // I karakteri 1, X karakteri 10 demek. İkisi de solundaki değer olan M den küçük, ama MCMI yı doğrı hesaplayıp MCMX i yanlış hesaplıyo. MCMXCIX sayısını da X gördüğü yerde yanlış hesaplamaya başlıyo. NEDEEENN (MCMI ve MCMX i ben ekledim MCMXCIX in neden çalışmadığını anlamak için.)
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
