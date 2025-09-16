#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (!q->front) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
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
// Updated on 2026-04-22
