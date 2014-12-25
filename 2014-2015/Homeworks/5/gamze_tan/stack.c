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
	struct stackNode *new = malloc(sizeof(struct stackNode));
	if (new != NULL) {
		new->data = data;
		new->next = *top;
		*top = new;
	} else {
		printf("%lf not inserted.No memory available.", data);
	}
	free(new);

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
	struct stackNode *temp;	//temporary node pointer
	double popval;
	temp = *top;
	popval = temp->data;	//node value
	if (temp == NULL) {
		return -1;
	} else {
		*top = (*top)->next;
		free(temp);
	}
	return popval;
}
