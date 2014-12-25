#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
struct stackNode * get_node(int item) {
   struct stackNode * temp;
   temp = (struct stackNode *) malloc(sizeof(struct stackNode));
   if (temp == NULL)
      printf("\nMemory Cannot be allocated");
   temp->data = item;
   temp->next = NULL;
   return (temp);
}
*/
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
	struct stackNode *topS;
	topS = (struct stackNode *)malloc(sizeof(struct stackNode));
	topS->data = data;
	topS->next = *top;
	*top = topS;
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
	struct stackNode *topS = *top;
	if (stack_is_empty(topS)) {
		return -1;
	} else {
		int top_data;
		topS = *top;
		*top = (*top)->next;
		top_data = topS->data;
		free(topS);

		return top_data;

	}
}
