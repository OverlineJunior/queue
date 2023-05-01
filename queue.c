#include <stdio.h>
#include <string.h>
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

// Moves every element 1 index to the left, discarding the first element.
void shift_queue(Queue* queue, int len) {
	for (int i = 1; i < len; i++) {
		queue->_elements[i - 1] = queue->_elements[i];
	}

	int last_index = len - 1;
	QueueMaybeInt none = { .is_some = false };
	queue->_elements[last_index] = none;
}

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

int queue_len(Queue queue) {
	return queue._len;
}

bool queue_is_empty(Queue queue) {
	return queue_len(queue) == 0;
}

QueueMaybeInt queue_peek_front(Queue queue) {
	return queue._elements[0];
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

QueueMaybeInt queue_dequeue(Queue* queue) {
	if (queue_is_empty(*queue)) {
		QueueMaybeInt none = { .is_some = false };
		return none;
	}

	QueueMaybeInt value = queue->_elements[0];

	shift_queue(queue, queue_len(*queue));
	queue->_len--;

	return value;
}

Queue queue_init(int elements[], int len) {
	Queue queue = queue_new();

	for (int i = 0; i < len; i++) {
		queue_enqueue(&queue, elements[i]);
	}

	return queue;
}

void queue_display(Queue queue) {
	int len = queue_len(queue);

	printf("<[");

	for (int i = 0; i < len; i++) {
		char el_text[16] = "%i";
		
		if (i < len - 1) {
			strcat_s(el_text, 16, ", ");
		}

		printf(el_text, queue._elements[i].value);
	}

	printf("]\n");
}
