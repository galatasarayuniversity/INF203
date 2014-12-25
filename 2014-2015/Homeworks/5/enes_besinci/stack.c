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
	struct stackNode *new;
	new = malloc(sizeof(struct stackNode));
	new->data = data;
	new->next = *top;
	*top = new;
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
	struct stackNode *temporary = *top;
	int popped_data;

	if (temporary == NULL) {
		return -1;
	} else {
		temporary = *top;
		popped_data = temporary->data;
		*top = (*top)->next;
		free(temporary);
		return popped_data;
	}
}
