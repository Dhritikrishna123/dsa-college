#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1; head->next = malloc(sizeof(struct Node));
    head->next->data = 2; head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3; head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4; head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5; head->next->next->next->next->next = NULL;

    printf("Middle element: %d\n", findMiddle(head));
    return 0;
}
// Updated on 2026-04-22
