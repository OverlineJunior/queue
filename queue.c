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

Queue queue_new(void) {
	Queue queue = { ._len = 0 };

	for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
		QueueMaybeInt none = { .is_some = false };
		queue._elements[i] = none;
	}

	return queue;
}

Queue queue_init(int elements[], int len) {
	Queue queue = queue_new();

	for (int i = 0; i < len; i++) {
		QueueMaybeInt some = {
			.is_some = true,
			.value = elements[i],
		};

		queue._elements[i] = some;
	}

	return queue;
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
