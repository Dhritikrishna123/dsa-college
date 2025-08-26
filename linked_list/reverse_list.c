#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1; head->next = malloc(sizeof(struct Node));
    head->next->data = 2; head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3; head->next->next->next = NULL;

    printf("Original: ");
    printList(head);
    head = reverse(head);
    printf("Reversed: ");
    printList(head);
    return 0;
}
// Updated on 2026-04-22
