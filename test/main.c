#include <stdio.h>
#include "../queue.h"

int main(void) {
	Queue queue = queue_new();
	queue_enqueue(&queue, 5);
	queue_enqueue(&queue, 10);
	printf("%i ", queue_peek_front(queue));
}
