#include <stdio.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int val) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = val;
    }
}

int pop(struct Stack* s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return -1;
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
