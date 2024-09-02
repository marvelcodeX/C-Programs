#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, capacity;
    int* queue;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->queue = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(struct Queue* q, int data) {
    // Check if the queue is full
    if (q->rear == q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }

    
    q->queue[++q->rear] = data;
}

void dequeue(struct Queue* q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = 0; i < q->rear; i++) {
        q->queue[i] = q->queue[i + 1];
    }

    q->rear--;
}

void display(struct Queue* q) {
    if (q->front > q->rear) {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d <-- ", q->queue[i]);
    }
    printf("\n");
}

void front(struct Queue* q) {
    if (q->rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Element is: %d\n", q->queue[q->front]);
}

int main() {
    struct Queue* q = createQueue(4);

    display(q);

    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    enqueue(q, 60);

    display(q);

    dequeue(q);
    dequeue(q);

    printf("After two node deletions\n");

    display(q);

    printf("After one insertion\n");
    enqueue(q, 60);

    display(q);

    front(q);

    free(q->queue);
    free(q);

    return 0;
}