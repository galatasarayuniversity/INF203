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
	struct node *new_elem;
	struct node *once;
	struct node *tmp;
	//int i;
	new_elem = (struct node *)malloc(sizeof(new_elem));	//yeni eleman
	new_elem->ssn = ssn;	//değerleri atadım
	new_elem->prio = prio;

	if (head == NULL) {
		head = new_elem;
		head->next = NULL;
	} else {
		/*for( i= 0 ; head->prio <= prio ; i++ ){
		   tmp  = head->next;
		   head->next = tmp->next;
		   }
		 */
		/*while( head->prio != prio+1 ){
		   once = head;
		   tmp  = head->next;
		   head = tmp;
		   }
		 */
		while (head->prio <= prio) {
			tmp = head;
			once = tmp;
			tmp = tmp->next;
			head = tmp;

		}
		new_elem->next = head;
		once->next = new_elem;

	}

	return head;
}

struct node *dequeue(struct node **head)
{
	struct node *tmp;
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
		int i = 1;
		printf("\nCurrent Queue:\n");
		printf("--------------\n");

		while (head) {
			printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i, priority_strings[head->prio], head->prio, head->ssn);
			head = head->next;
			i += 1;
		}
		printf("\n");
	}
}
