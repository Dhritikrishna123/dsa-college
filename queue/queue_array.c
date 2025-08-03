#include <stdio.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear < MAX - 1) {
        if (q->front == -1) q->front = 0;
        q->items[++q->rear] = val;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    int val = q->items[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return val;
}

int main() {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
