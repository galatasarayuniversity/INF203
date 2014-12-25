/*
 * stack.c
 *
 *  Created on: Nov 30, 2014
 *      Author: yc
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stack_free(struct stackNode **top)
{
	struct stackNode *ttop = *top;
	while (ttop != NULL) {
		struct stackNode *orphan = ttop;
		ttop = ttop->next;
		free(orphan);
	}
	*top = NULL;
}

/* TODO */
void stack_push(struct stackNode **top, double data)
{

	struct stackNode *temp;
	temp = malloc(sizeof(struct stackNode));
	temp->data = data;

	temp->next = *top;
	*top = temp;

}

void stack_print(struct stackNode *top)
{
	/* Stack bos mu? */
	if (!stack_is_empty(top)) {
		printf("(");
		while (top != NULL) {
			printf("%3.2f -> ", top->data);
			top = top->next;
		}
		printf("NULL)\n");
	} else {
		printf("(EMPTY)\n");
	}
}

/* TODO */
double stack_pop(struct stackNode **top)
{

/* Stack bos ise -1 dondurelim. */

	double a;
	if (*top == NULL) {

		return -1;
	} else {

		a = (*top)->data;
		*top = (*top)->next;

	}

	return a;

}
