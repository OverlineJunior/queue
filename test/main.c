#include <stdio.h>
#include "../queue.h"

int main(void) {
	Queue queue = queue_new();
	printf("%i ", queue_is_empty(queue));
	queue_enqueue(&queue, 5);
	printf("%i ", queue_is_empty(queue));
}
