/*
 * rpn_main.c
 *
 *  Created on: Nov 30, 2014
 *      Author: yc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"

int DEBUG = 1;

/* TODO: op1 ve op2'yi operation ile verilen '+', '-', '*', '/'
 *  islemlerini uygulayip geri donduren fonksiyonu yazin. */
double compute_operation(double op1, double op2, char operation)
{

	switch (operation) {

	case '+':

		return op1 + op2;

	case '-':
		return op1 - op2;

	case '*':
		return op1 * op2;

	case '/':
		return op1 / op2;

	}

}

double evaluate_RPN(char *expr, struct stackNode **top)
{
	int i;
	double popVal1;		// Stack'ten cikaracaginiz (pop) ilk deger
	double popVal2;		// Stack'ten cikaracaginiz (pop) ikinci deger
	double pushVal;		// Stack'e ekleyeceginiz (push) deger
	double retval = 0;

	/* TODO: Ifadenin sonuna kadar elemanlari gezecek ('\0') bir dongu kurunuz */
	for (i = 0; *(expr + i) != '\0'; i++) {
		/* TODO: Eger eleman islenen (operand) ise stack'e ekleyiniz (push)
		 * Soru: Bir karakterin sayi karsiligini nasil buluyorduk? */

		if (*(expr + i) < 58 && *(expr + i) > 47) {
/*Hocam Merhaba ;

* Bu noktada karakterin sayi kariligini nasil buluyorduk diye sormuşsunuz ancak
* biz expr'in point ettiği stringe ascii karakterleri yazdigimizda bizim
* girdimizi decimal degerleri sayi olarak girmekte. Bu noktada bu decimal degerleri
* (double)*(expr+i) vb gibi bircok şekilde karaktere donusturmeye calissam da
* nedenini anlayamayarak basarili olamadım. Bu yuzden uzulerek kolpaya yatiyor ve
* programin dogru cikti verebilmesi icin (decimal_deger)-48 yapiyorum.
*/
			stack_push(top, (*(expr + i)) - 48);

			if (DEBUG)
				stack_print(*top);
		} else if (*(expr + i) == '+' || *(expr + i) == '-' || *(expr + i) == '/' || *(expr + i) == '*') {
			/* TODO: Eger eleman bir islem ise stack'ten iki deger cekiniz (pop) */
			popVal1 = stack_pop(top);
			popVal2 = stack_pop(top);

			if (DEBUG)
				stack_print(*top);

			pushVal = compute_operation(popVal2, popVal1, *(expr + i));
			/* TODO: Bu iki deger ile istenen islemi compute_operation()
			 * fonksiyonuna verip donus degeri stack'e push edin. */
			stack_push(top, pushVal);

			if (DEBUG)
				stack_print(*top);
		}
	}

	/* TODO: Stack'te kalan elemani cekip return edin. */
	retval = stack_pop(top);

	if (!stack_is_empty(*top)) {
		fprintf(stderr, "UYARI: Stack hala dolu, RPN ifadesi dengesiz veya algoritmayi yanlis kurdunuz.\n");
	}
	return retval;

}

int main(int argc, char *argv[])
{
	int continuing = 1;
	char line[LINE_MAX];

	struct stackNode *stack = NULL;

	printf("RPN Hesap Makinesi\nCikis icin exit yazip ENTER'a basin\n\n");

	while (continuing) {
		printf(">> ");
		fgets(line, sizeof(line), stdin);
		line[strlen(line) - 1] = '\0';

		/* Exit verildiyse donguden cik */
		if (strcmp(line, "exit") == 0) {
			continuing = 0;
		} else if (strcmp(line, "DEBUG") == 0) {
			DEBUG = !DEBUG;
			printf("DEBUG: %s\n", (DEBUG) ? "ACIK" : "KAPALI");
		} else if (line[0] != '\0') {
			printf("CEVAP: %.2f\n", evaluate_RPN(line, &stack));
			if (stack != NULL) {
				stack_free(&stack);
			}
		}
	}

	/* Test */
	DEBUG = 0;
	assert(evaluate_RPN("13+2-", &stack) == 2.0);
	assert(evaluate_RPN("62+5*84/-", &stack) == 38.0);
	printf("Tests passed.\n");

	return 0;
}
