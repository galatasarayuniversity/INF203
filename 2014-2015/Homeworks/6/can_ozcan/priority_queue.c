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
	struct node *search = head;
	struct node *avant = malloc(sizeof(struct node));
	struct node *tmp = malloc(sizeof(struct node));
	avant->next = head;
	tmp->next = NULL;
	tmp->prio = prio;
	tmp->ssn = ssn;
	if (head == NULL) {
		head = tmp;
	} else {
		while (search->next != NULL) {
			if (search->prio <= prio) {
				avant->next = search;
				tmp = search;
				search = search->next;
			} else {
				avant->next = tmp;
				tmp->next = search;
				break;
			}
		}
	}
	return head;
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
