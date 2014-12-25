/*
 * priority_queue.c
 *
 *  Created on: 30 Kas 2014
 *      Author: mazlum
 */

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
	assert(new != NULL);
	new->prio = prio;
	new->ssn = ssn;

	/*struct node *gecici;
	   gecici = malloc(sizeof(struct node));
	   // gecici=head; */
	if (is_empty(head)) {
		new = head;
		return head;
	} else {
		int i = 0;
		for (i = 0; head != NULL; i++) {
			head = head->next;
			if (new->prio > head->prio) {
				new->next = head;
				head = new;
				break;
			}
		}
	}
	return head;

}

struct node *dequeue(struct node **head)
{
	if (*head) {
		struct node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return head;
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
