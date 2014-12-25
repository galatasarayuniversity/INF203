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
	struct stackNode *node = (struct stackNode *)malloc(sizeof(struct stackNode));
	node->data = data;
	node->next = *top;
	*top = node;
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
	struct stackNode *node;
	if (stack_is_empty(*top) == 0) {
		node = *top;
		double data = node->data;
		*top = node->next;
		free(node);
		return data;
	}
	//else{
	return -1;
}

    /* Stack bos ise -1 dondurelim. */
