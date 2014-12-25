/*
 * priority_queue.c
 *
 *  Created on: 1 Ara 2014
 *      Author: fatih
 */

/*
* priority_queue.c
*
* Created on: Nov 21, 2014
* Author: gsu
*/

/*
Sınıfta tp'de yaptığımızda sürekli kalp hastası alıp onu cıkartıp tekrar kalp hastası alıyordu. Kodu uğraştım düzeltmeye çalıştım.
Su an kodu incelediğimde hata göremiyorum, derleyici de hata vermiyor.Terminalde derlerken pointer eşleşmesi hatası gibi bir şey alıyorum 
sanırım pointer baglamadan dolayı kodum düzgün calısmıyor.
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

int is_empty(struct node *head)
{
	return (head == NULL);
}

struct node *enqueue(struct node *head, enum Priority prio, int ssn)
{

	struct node *new = NULL;
	struct node *gecici;
	new = malloc(sizeof(struct node));
	gecici = malloc(sizeof(struct node));
	new->prio = prio;
	new->ssn = ssn;
	if (!is_empty(head)) {
		return new;
	} else {
		if (head->next != NULL && head->ssn != NULL) {
			gecici = head->next;

			if (new->prio >= head->prio) {
				head = head->next;
				gecici = head;
			} else {
				new->next = head;
				gecici->next = new;
			}
		} else {
			head = new;
		}
		return head;
	}
}

struct node *dequeue(struct node **head)
{
	struct node *new = *head;
	new = malloc(sizeof(struct node));
	if (!is_empty(*head)) {
		printf("sirada kimse yok/n");
	} else {
		new->next = new;
	}

	return new;
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
