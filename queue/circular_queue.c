#include <stdio.h>

#define MAX 100

struct CircularQueue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct CircularQueue* q) {
    q->front = q->rear = -1;
}

void enqueue(struct CircularQueue* q, int val) {
    if ((q->front == 0 && q->rear == MAX - 1) ||
        (q->rear == q->front - 1)) {
        printf("Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else if (q->rear == MAX - 1 && q->front != 0) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = val;
}

int dequeue(struct CircularQueue* q) {
    if (q->front == -1) return -1;
    int val = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == MAX - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return val;
}

int main() {
    struct CircularQueue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
// Updated on 2026-04-22
