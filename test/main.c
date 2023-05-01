#include <stdio.h>
#include "../queue.h"

int main(void) {
	int elements[] = {5, 10, 15};
	Queue queue = queue_init(elements, 3);
	queue_display(queue);

	queue_dequeue(&queue);
	queue_display(queue);

	queue_dequeue(&queue);
	queue_display(queue);

	queue_dequeue(&queue);
	queue_display(queue);
}
