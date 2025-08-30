#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1; head->next = malloc(sizeof(struct Node));
    head->next->data = 2; head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3; head->next->next->next = head;

    printf("Has cycle: %s\n", hasCycle(head) ? "Yes" : "No");
    return 0;
}
// Updated on 2026-04-22
