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

	struct stackNode *yeni;
	yeni = malloc(sizeof(struct stackNode));
	yeni->data = data;
	yeni->ileri = *top;
	*top = yeni;

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

	struct stackNode *tmp = *top;

	if (tmp != NULL) {
		tmp->data = data;
		tmp = *top;
		*top = (*top)->ileri;
		*top->icerik = tmp->icerik;
		free(tmp);
		return *top->data;
	}

	else {
		return -1;
	}

}
