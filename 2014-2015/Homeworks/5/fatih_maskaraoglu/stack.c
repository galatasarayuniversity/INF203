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
	struct stackNode *gecici = *top;
	if (!stack_is_empty(top)) {
		gecici->next = NULL;
		gecici->data = data;
	} else {
		struct stackNode *new = NULL;
		new->next = gecici;
		new->data = data;
	}
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
	if (!stack_is_empty(top)) {
		return -1;
	} else {
		double x;
		struct stackNode *gecici = *top;
		x = gecici->data;
		gecici = gecici->next;
		return x;
	}
}
