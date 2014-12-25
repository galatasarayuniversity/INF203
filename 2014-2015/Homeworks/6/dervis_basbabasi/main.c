#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "priority_queue.h"

int main(int argc, const char *argv[])
{
	struct node *queue = NULL;
	int i;
	srand(time(NULL));

	for (i = 0; i < 10; i++) {
		int ssn = (rand() % 1001) + 1000;
		int sickness = (rand() % MAX_PRIO);
		queue = enqueue(queue, sickness, ssn);
		print_queue(queue);

		sleep(1);

		if ((rand() % 2) && (rand() % 2)) {
			/* Dequeue */
			struct node *out = dequeue(&queue);
			printf("****[%12s (priority: %d)] is now out of the queue!\n", priority_strings[out->prio], out->prio);
		}
	}
	//printf("%d",PRIO_HEART_ATTACK);

	return 0;
}
