#include <stdio.h>

void countingSort(int arr[], int n) {
    int output[n];
    int count[100] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i < 100; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
