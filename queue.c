#include <stdbool.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
	int elements[QUEUE_MAX_SIZE];
} Queue;

Queue queue_new() {
	
}

Queue queue_init(int elements[]) {
	
}

void queue_enqueue(Queue queue, int value) {

}

int queue_dequeue(Queue queue) {
	return 0;
}

int queue_peek_front(Queue queue) {
	return 0;
}

int queue_len(Queue queue) {
	return 0;
}

bool queue_is_empty(Queue queue) {
	return false;
}
