#include <stdio.h>

void delete(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*n)--;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5;

    delete(arr, &n, 2);

    printf("After deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
