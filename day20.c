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

    int count = 0;

    // Check all subarrays
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                count++;
            }
        }
    }

    // Print result
    printf("%d\n", count);

    return 0;
}