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
	struct node *newNode = malloc(sizeof(struct node));
	newNode->prio = prio;
	newNode->ssn = ssn;
	newNode->next = NULL;
	struct node *temp = head->next;
	struct node *prev = head;

	if (is_empty(head)) {
		head->next = newNode;
	}

	else
		while (temp->prio <= prio) {
			temp = temp->next;
			prev = prev->next;
		}

	newNode->next = temp;
	prev->next = newNode;

	free(temp);
	free(prev);

	return head;
}

struct node *dequeue(struct node **head)
{
	if (is_empty(*head)) {
		printf("there is no line!\n");
		return head;
	} else {
		struct node *first = *head;
		*head = (*head)->next;
		return first;
	}

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
