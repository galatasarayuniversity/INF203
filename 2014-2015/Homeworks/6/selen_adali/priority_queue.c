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
	struct node *yeni = NULL;
	struct node *onceki = NULL;
	yeni = malloc(sizeof(struct node));
	onceki = malloc(sizeof(struct node));
	yeni->prio = prio;
	yeni->ssn = ssn;
	while (head->next != NULL) {
		if (yeni->prio < head->prio) {
			yeni->next = head;
			yeni = head;
		} else {
			onceki = head;
			head = head->next;

			yeni->next = head;
			onceki->next = yeni;
		}
	}
	if (yeni->prio < head->prio) {
		yeni->next = head;
		yeni = head;

	} else {
		yeni->next = NULL;
		head->next = yeni;
	}

	return yeni;

}

struct node *dequeue(struct node **head)
{

	struct node *tmp = *head;
	*head = tmp->next;
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
