#include <stdio.h>
#include "../queue.h"

int main(void) {
	int elements[] = {5, 10, 15};
	Queue queue = queue_init(elements, 3);
	printf("%i ", queue_peek_front(queue).value);

	queue_dequeue(&queue);
	printf("%i ", queue_peek_front(queue).value);

	queue_dequeue(&queue);
	printf("%i ", queue_peek_front(queue).value);

	queue_dequeue(&queue);
	printf("%i ", queue_peek_front(queue).value);
}
