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
	struct node *tmp;
	struct node *tmp_past;

	new = malloc(sizeof(struct node));

	tmp = head;		//head adresi yerine tmp kullanilacak

	new->prio = prio;
	new->ssn = ssn;

	if (is_empty(head)) {
		new->next = NULL;
		return new;
	} else if (!is_empty(head)) {

		if (prio >= tmp->prio) {	//düsük öncelik eklenme durumu
			new->next = NULL;
			tmp->next = new;
		} else if (tmp->prio > prio) {
			new->next = tmp;
			tmp->next = NULL;
		}

	}

}

struct node *dequeue(struct node **head)
{

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
