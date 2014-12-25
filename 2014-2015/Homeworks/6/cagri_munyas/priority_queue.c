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
	struct node *tmp = NULL, *new = NULL, *tmprev = NULL;
	if (head == NULL) {
		head = malloc(sizeof(struct node) * 10);
		head->prio = prio;
		head->ssn = ssn;
		head->next = NULL;
	} else {
		/* new->prio = prio;
		   new->ssn = ssn;
		   new->next = head;
		   head = new;
		   tmp = head->next; */
		tmp = head;
		while (prio >= tmp->prio && tmp != NULL) {
			tmp = tmprev;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			tmprev->next = tmp;
			tmp->prio = prio;
			tmp->ssn = ssn;
			tmp->next = NULL;
		} else {
			new->next = tmp;
			tmprev->next = new;
			new->prio = prio;
			new->ssn = ssn;
		}
	}
}

struct node *dequeue(struct node **head)
{
	struct node *tmp = NULL, *dq;
	dq = *head;
	tmp = *head;
	dq = dq->next;
	*head = dq;
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
