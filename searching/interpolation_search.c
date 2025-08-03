#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 8, 12, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    int result = interpolationSearch(arr, n, x);
    printf("Element found at index: %d\n", result);
    return 0;
}
