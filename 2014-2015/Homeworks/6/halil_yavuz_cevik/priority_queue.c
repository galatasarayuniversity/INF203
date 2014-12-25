/*
 * priority_queue.c
 *
 *  Created on: Nov 30, 2014
 *      Author: yc
 */

// SORULARIN CEVAPLARI EN ASAGIDA VERILMISTIR

#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "priority_queue.h"

const char *priority_strings[] = { "Heart attack", "Fracture", "Fever",
	"Nausea", "Sore throat",
	NULL,
};

struct node *enqueue(struct node *head, enum Priority prio, int ssn)
{

	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	struct node *tmp2 = (struct node *)malloc(sizeof(struct node));
	struct node *previous_tmp2 = (struct node *)malloc(sizeof(struct node));

	tmp->prio = prio;
	tmp->ssn = ssn;
	tmp->next = NULL;
	tmp2 = head;

// Liste bossa liste basina ekleme yapiyoruz
	if (head == NULL) {

		return tmp;

	}

	/*Liste bos degil ve listenin ilk elemaninin onceligi
	 * ekleyecegimiz elemanin önceliginden daha düsük. Eleman
	 * yine basa ekleniyor*/

	if ((tmp2->prio) > (tmp->prio)) {
		tmp->next = tmp2;
		head = tmp;

	}

	/*Ekleyecegimiz elemandan daha oncelikli elemanlar var.
	 * Liste icinde dolasacagız*/

	else {

//Ekleyecegimiz eleman ara oncelikli veya en onceliksiz ise
		while ((tmp2->prio) <= (tmp->prio) && tmp2->next != NULL) {

			previous_tmp2 = tmp2;
			tmp2 = tmp2->next;

		}

//Listede oncelik siralamasina gore araya konuldu

		if (tmp2->next != NULL) {
			tmp->next = tmp2;
			previous_tmp2->next = tmp;
		}

//Ekledigimiz eleman son eleman haric listedeki her elemandan daha onceliksiz. Son elemana bakiyoruz
		if (tmp2->next == NULL) {

// Ekleyecegimiz eleman listenin son elemaniyla ayni oncelige sahipse, elemani en sona ekleyecegiz
			if (tmp2->prio == tmp->prio) {

				tmp2->next = tmp;
			}

//Ekleyecegimiz eleman listenin son elemanindan daha büyükse son elemandan bir oncesine yerlestiriyoruz
			else if ((tmp2->prio) > (tmp->prio)) {

				tmp->next = tmp2;
				previous_tmp2->next = tmp;
			}

		}

		return head;

	}

	return head;
}

struct node *dequeue(struct node **head)
{

	struct node *tmp = *head;

	//Kuyruk bos mu kontrolu
	if (is_empty(*head) == 1) {

		printf("Hata! Kuyruk Bos! \n");

	}

	else {

		*head = (*head)->next;

	}

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

/*								SORULAR'IN CEVAPLARI
 *
 * 1-) int ssn = (rand() % 1001) + 1000; ilk olarak rand() %1001 ile 0-1000 arasi
 *
 * sayilar urettik. Daha sonra bu araliga 1000 ekliyoruz. Sonuc olarak 1000-2000 arasi
 *
 * sayilar uretmis olduk.
 *
 *
 * 2-)dequeue fonksiyonumda 1 if 1 else'den sonra return degeri vardır. Döngü yoktur. if de else de birim
 *
 * zamanda calisan islemlerdir dolayisiyla dequeue fonksiyonunu O(1) olarak gösteriyoruz.
 *
 *
 * 3-)enqueue fonksiyonumda birim zamanda calisan if ve elseleri dikkate almiyorum. Sadece 1 adet while var ve
 *
 * o da O(n-1) şeklinde gösterilecek (kuyrugun eleman sayisi n). O(n-1)=O(n). Sonuc olarak O(n) olarak gösteriyoruz.
 *
 */
