
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

	struct node *new;
	new = malloc(sizeof(struct node));
	new->prio = prio;
	new->ssn = ssn;
	new->next = NULL;
	if (head == NULL) {
		return new;
	} else if (head->prio > prio) {
		new->next = head;
		return new;
	} else if (head->prio <= prio) {
		if (head->next == NULL) {
			head->next = new;
			return head;
		} else {
			struct node *tmp;
			struct node *p;
			tmp = head->next;
			p = head;
			while (tmp) {
				if (tmp->prio > prio) {
					new->next = tmp;
					p->next = new;
					return head;
				} else {
					if (tmp->next == NULL) {
						tmp->next = new;
						return head;
					}
					p = p->next;
					tmp = tmp->next;
				}
			}
		}
	}
	return head;
}

struct node *dequeue(struct node **head)
{
	struct node *dequeued = *head;
	*head = (*head)->next;
	return dequeued;
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
