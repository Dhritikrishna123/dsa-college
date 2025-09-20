#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

void initQueue(struct PriorityQueue* q) {
    q->front = NULL;
}

void enqueue(struct PriorityQueue* q, int data, int priority) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (!q->front || priority < q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
    } else {
        struct Node* temp = q->front;
        while (temp->next && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(struct PriorityQueue* q) {
    if (!q->front) return -1;
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

int main() {
    struct PriorityQueue q;
    initQueue(&q);
    enqueue(&q, 10, 3);
    enqueue(&q, 20, 1);
    enqueue(&q, 30, 2);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
// Updated on 2026-04-22
