#include <stdio.h>

int main() {
    int n;

    // Read size
    scanf("%d", &n);

    int arr[n];

    // Read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // If k > n, reduce it
    k = k % n;

    // Rotate k times
    for(int i = 0; i < k; i++) {
        int last = arr[n - 1];

        // Shift elements right
        for(int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }

        arr[0] = last;
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}