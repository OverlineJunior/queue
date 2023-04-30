#include <stdbool.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
	int elements[QUEUE_MAX_SIZE];
} Queue;

Queue queue_new(void);
Queue queue_init(int elements[]);
void queue_enqueue(Queue queue, int value);
int queue_dequeue(Queue queue);
int queue_peek_front(Queue queue);
int queue_len(Queue queue);
bool queue_is_empty(Queue queue);
