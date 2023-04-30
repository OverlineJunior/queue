#include <stdbool.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
	int value;
	bool is_some;
} QueueMaybeInt;

typedef struct {
	QueueMaybeInt _elements[QUEUE_MAX_SIZE];
	int _len;
} Queue;

Queue queue_new(void);
Queue queue_init(int elements[], int len);
void queue_enqueue(Queue* queue, int value);
int queue_dequeue(Queue queue);
int queue_peek_front(Queue queue);
int queue_len(Queue queue);
bool queue_is_empty(Queue queue);
