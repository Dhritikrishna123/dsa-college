#include <stdio.h>

void insert(int arr[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    (*n)++;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5;

    insert(arr, &n, 2, 10);

    printf("After insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
// Updated on 2026-04-22
