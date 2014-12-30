#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "priority_queue.h"

const char *priority_strings[] = { "Heart attack", "Fracture", "Fever",
		"Nausea", "Sore throat",
		NULL, };

struct node* enqueue(struct node *head, enum Priority prio, int ssn) {
	struct node *tmp = head;
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	new_node->prio = prio;
	new_node->ssn = ssn;
	new_node->next = NULL;

	if (head == NULL) {
		new_node = head;
		return head;
	} else

	{
		while (tmp) {

			tmp = tmp->next;
		}
		if (new_node->prio < tmp->prio)

		{

			new_node->next = head;
			head = new_node;

		} else
			tmp->next = new_node;
		new_node->next = NULL;

	}

}
struct node* dequeue(struct node **head) {

	struct node *yeni1 = *head;
	yeni1->next = (*head);
	return yeni1;
}

int is_empty(struct node *head) {
	return (head == NULL);
}

void print_queue(struct node *head) {
	if (!is_empty(head)) {
		printf("\nCurrent Queue:\n");
		printf("--------------\n");
		int i = 1;
		while (head) {
			printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i,
					priority_strings[head->prio], head->prio, head->ssn);
			head = head->next;
			i += 1;
		}
		printf("\n");
	}
}


