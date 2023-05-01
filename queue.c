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

QueueMaybeInt first_empty_index(Queue queue) {
	for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
		if (!queue._elements[i].is_some) {
			QueueMaybeInt some = {
				.is_some = true,
				.value = i,
			};

			return some;
		}
	}

	QueueMaybeInt none = { .is_some = false };
	return none;
}

Queue queue_new(void) {
	Queue queue = { ._len = 0 };

	for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
		QueueMaybeInt none = { .is_some = false };
		queue._elements[i] = none;
	}

	return queue;
}

void queue_enqueue(Queue* queue, int value) {
	QueueMaybeInt index = first_empty_index(*queue);
	if (!index.is_some) return;

	QueueMaybeInt wrapped_value = {
		.is_some = true,
		.value = value,
	};

	queue->_elements[index.value] = wrapped_value;
	queue->_len++;
}

int queue_dequeue(Queue queue) {
	return 0;
}

QueueMaybeInt queue_peek_front(Queue queue) {
	return queue._elements[0];
}

Queue queue_init(int elements[], int len) {
	Queue queue = queue_new();

	for (int i = 0; i < len; i++) {
		queue_enqueue(&queue, elements[i]);
	}

	return queue;
}

int queue_len(Queue queue) {
	return queue._len;
}

bool queue_is_empty(Queue queue) {
	return queue_len(queue) == 0;
}
