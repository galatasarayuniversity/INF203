#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "priority_queue.h"

int main(int argc, const char *argv[])
{
	srand(time(NULL));
	struct node *queue = NULL;
	int i;

	for (i = 0; i < 10; i++) {
		//1000 ile 2000 arasında ssn üretti
		int ssn = (rand() % 1001) + 1000;
		//0-4 arasında rast hastalık üretti
		int sickness = (rand() % MAX_PRIO);
		queue = enqueue(queue, sickness, ssn);
		print_queue(queue);
		//1 sn oyunca işlemci sizin programınızı askıya alır

		sleep(1);
		//and kapısı gibi mantıksal ve işlemi yani olasılık kulladık
		if ((rand() % 2) && (rand() % 2)) {
			/* bir kişiyi sıradan çıkarıyor */
			struct node *out = dequeue(&queue);
			printf("****[%12s (priority: %d, ssn: %d)] is now out of the queue!\n", priority_strings[out->prio], out->prio, out->ssn);
			free(out);
		}
	}

	return 0;
}
