#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "priority_queue.h"

const char *priority_strings[] = {
	"Heart attack",
	"Fracture",
	"Fever",
	"Nausea",
	"Sore throat",
	NULL,
};

struct node *enqueue(struct node *head, enum Priority prio, int ssn)
{
	struct node *tmp1 = NULL, *tmp2 = head;
	struct node *new = malloc(sizeof(struct node));
	new->ssn = ssn;
	new->prio = prio;
	new->next = NULL;
	if (tmp2 == NULL)
		return new;
	while (1) {
		if (prio < tmp2->prio) {
			if (tmp1 == NULL) {
				new->next = tmp2;
				return new;
			} else {
				tmp1->next = new;
				new->next = tmp2;
				return head;
			}
		} else {
			if (tmp2->next == NULL) {
				tmp2->next = new;
				return head;
			}
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}

	}
}

struct node *dequeue(struct node **head)
{
	struct node *tmp = *head;
	*head = (*head)->next;
	return tmp;

}

int is_empty(struct node *head)
{
	return (head == NULL);
}

void print_queue(struct node *head)
{
	if (!is_empty(head)) {
		printf("\nCurrent Queue:\n");
		printf("--------------\n");
		int i = 1;
		while (head) {
			printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i, priority_strings[head->prio], head->prio, head->ssn);
			head = head->next;
			i += 1;
		}
		printf("\n");
	}
}
