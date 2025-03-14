#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    if (q->rear == MAX - 1) {
        return 1;  // Queue is full
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    if (q->front == -1) {
        return 1;  // Queue is empty
    }
    return 0;
}

// Function to enqueue (add an element to the queue)
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {  // If the queue is empty, set front to 0
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove an element from the queue)
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Indicates empty queue
    }
    int dequeuedValue = q->items[q->front];
    if (q->front == q->rear) {  // If there is only one element
        q->front = q->rear = -1;  // Reset queue to empty
    } else {
        q->front++;
    }
    return dequeuedValue;
}

// Function to display the queue
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);  // Enqueue 10
    enqueue(&q, 20);  // Enqueue 20
    enqueue(&q, 30);  // Enqueue 30
    enqueue(&q, 40);  // Enqueue 40
    enqueue(&q, 50);  // Enqueue 50
    displayQueue(&q);  // Display queue

    // Try to enqueue into a full queue
    enqueue(&q, 60);  // Queue is full, so this will fail

    printf("Dequeued: %d\n", dequeue(&q));  // Dequeue one element
    displayQueue(&q);  // Display the updated queue

    printf("Dequeued: %d\n", dequeue(&q));  // Dequeue another element
    displayQueue(&q);  // Display the updated queue

    return 0;
}
