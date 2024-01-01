#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
typedef struct {
    int head, tail, size;
    int *items;
} Queue;

// Function to initialize an empty queue with a given buffer size
void queue_init(Queue *queue, int bufferSize) {
    queue->head = -1;
    queue->tail = -1;
    queue->size = bufferSize;
    queue->items = (int *)malloc(bufferSize * sizeof(int));

    if (queue->items == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

// Function to check if the queue is empty
int queue_isEmpty(Queue *queue) {
    return (queue->head == -1 && queue->tail == -1);
}

// Function to check if the queue is full
int queue_isFull(Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

// Function to enqueue an element into the queue
void queue_push(Queue *queue, int value) {
    if (queue_isFull(queue)) {
        printf("Queue is full. Cannot push.\n");
        return;
    }

    if (queue_isEmpty(queue)) {
        queue->head = 0;
        queue->tail = 0;
    } else {
        queue->tail = (queue->tail + 1) % queue->size;
    }

    queue->items[queue->tail] = value;
    printf("pushed elements: %d\n", value);
}

// Function to dequeue an element from the queue
int queue_pop(Queue *queue) {
    int dequeuedItem;

    if (queue_isEmpty(queue)) {
        printf("Queue is empty. Cannot pop.\n");
        return -1;
    } else if (queue->head == queue->tail) {
        dequeuedItem = queue->items[queue->head];
        queue->head = -1;
        queue->tail = -1;
    } else {
        dequeuedItem = queue->items[queue->head];
        queue->head = (queue->head + 1) % queue->size;
    }

    printf("Poped elements: %d\n", dequeuedItem);
    return dequeuedItem;
}

// Function to display the elements in the queue
void queue_display(Queue *queue) {
    int i;

    if (queue_isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d ", queue->items[i]);
    }
    printf("%d\n", queue->items[i]);
}

// Function to free the allocated memory for the queue
void queue_deinit(Queue *queue) {
    free(queue->items);
}

int main(void) {
    int bufferSize = 5;  // Set your desired buffer size
    Queue myQueue;

    // Initialize the queue
    queue_init(&myQueue, bufferSize);

    // Enqueue elements
    queue_push(&myQueue, 10);
    queue_push(&myQueue, 20);
    queue_push(&myQueue, 30);

    // Display the queue
    queue_display(&myQueue);

    // Dequeue an element
    int dequeuedValue = queue_pop(&myQueue);

    if (dequeuedValue != -1) {
        printf("poped value: %d\n", dequeuedValue);
    }

    // Display the updated queue
    queue_display(&myQueue);

    // Free the allocated memory
    queue_deinit(&myQueue);

    return 0;
}
