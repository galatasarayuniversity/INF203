
/* Aciliyetine gore hastalik seviyeleri */
enum Priority {
	PRIO_HEART_ATTACK,	// 0
	PRIO_FRACTURE,		// 1
	PRIO_FEVER,		// 2
	PRIO_NAUSEA,		// 3
	PRIO_SORE_THROAT,	// 4
	MAX_PRIO,		// 5
};

struct node {
	/* Aciliyet bilgisi */
	enum Priority prio;
	/* Sosyal guvenlik numarasi */
	int ssn;

	struct node *next;
};

extern const char *priority_strings[];

struct node *enqueue(struct node *head, enum Priority prio, int ssn);
struct node *dequeue(struct node **head);
void print_queue(struct node *head);
int is_empty(struct node *head);
