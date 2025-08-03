#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    if (*head) {
        struct Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
}

void printList(struct Node* head) {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    return 0;
}
