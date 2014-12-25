#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "priority_queue.h"

const char *priority_strings[] = { "Heart attack", "Fracture", "Fever",
	"Nausea", "Sore throat",
	NULL,
};

struct node *enqueue(struct node *head, enum Priority prio, int ssn)
{

	struct node *new;
	struct node *tmp_head;
	struct node *point;

	tmp_head = malloc(sizeof(struct node));
	tmp_head = head;
	point = malloc(sizeof(struct node));
	point = tmp_head;
	new = malloc(sizeof(struct node));
	new->ssn = ssn;
	new->prio = prio;
	new->next = NULL;

	if (head == NULL) {

		head = new;
		return head;

	} else if (new->prio < tmp_head->prio) {

		new->next = tmp_head;

		return new;
	}

	else if (new->prio >= tmp_head->prio) {

		while (new->prio >= tmp_head->prio && tmp_head->next != NULL) {
			point = tmp_head;
			tmp_head = tmp_head->next;

		}
		if (tmp_head->next == NULL && new->prio >= tmp_head->prio) {
			tmp_head->next = new;
		} else {

			point->next = new;
			new->next = tmp_head;

		}
		return head;
	}

}

struct node *dequeue(struct node **head)
{
	struct node *tmp = *head;
	(*head) = (*head)->next;
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
