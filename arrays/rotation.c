#include <stdio.h>

void rotateLeft(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    rotateLeft(arr, n);

    printf("After rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
