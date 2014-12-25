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

	struct node *new = malloc(sizeof(struct node));
	struct node *tmp = head;
	struct node *tmp2 = tmp;
	if (new == NULL) {
		printf("Malloc hatasi.\n");
		return head;
	}

	new->prio = prio;
	new->ssn = ssn;
	new->next = NULL;

	if (is_empty(head)) {
		head = new;
	} else if (head->next == NULL) {
		if (head->prio <= prio) {
			head->next = new;
		} else {
			new->next = tmp;
			head = new;
		}
	} else {
		while (prio >= tmp->prio && tmp->next != NULL) {
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (prio >= tmp->prio && tmp->next == NULL) {
			tmp->next = new;
		} else if (prio < tmp->prio && tmp->next != NULL && head != tmp) {
			tmp2->next = new;
			new->next = tmp;
		} else {
			new->next = tmp;
			head = new;
		}
	}
	return head;
}

struct node *dequeue(struct node **head)
{
	struct node *tmp = malloc(sizeof(struct node));
	tmp = *head;
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
