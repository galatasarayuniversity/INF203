#include <stdio.h>
#include <assert.h>

/* Soru 1 */
int r_strchr(char *string, char c)
{
	int i;
    if (*string == c)
    {
    	return 1;
    }
    else if (*string == 0)
    {
    	return 0;
    }
    else
    {
    	return r_strchr(1 + string , c);
    }
}

/* Soru 2 */
int r_strlen(char *string)
{
	if (*string == '\0')
	{
		return 0;
	}
	else
	{
		string++;
		return 1 + r_strlen(string);
	}
}

/* Soru 3 */
int r_strcount(char *string, char c)
{
	if (*string == '\0')
	{
		return 0;
	}
	else if (*string == c)
	{
		string++;
		return 1 + r_strcount(string, c);
	}
	else
	{
		string++;
		return r_strcount(string,c);
	}
}

/* Soru 4 Yardimci fonksiyon */
int roman_digit_to_int(char c)
{
	switch(c)
	{
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			printf("Hatali tuslama!!");
			return 0;
			break;
	}
}

/* Soru 4 Esas fonksiyon */
int roman_number_to_int(char *string)
{
	if(*(1 + string) ==  '\0')
	{
		return roman_digit_to_int(*string);
	}
	else
	{
		if(roman_digit_to_int(*string) >= roman_digit_to_int(*(1 + string)))
		{
			return roman_digit_to_int(*string) + roman_number_to_int(1 + string);
		}
		else
		{
			return roman_number_to_int(1 + string) - roman_digit_to_int(*string);
		}
	}
}

int r_sum_digits(int x)
{
	if (x != 0)
	{
		return ( x % 10 + r_sum_digits (x / 10) );
	}
	else
	{
		return 0;
	}
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
