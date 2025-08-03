#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* s) {
    s->top = NULL;
}

void push(struct Stack* s, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack* s) {
    if (!s->top) return -1;
    struct Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int main() {
    struct Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    return 0;
}
