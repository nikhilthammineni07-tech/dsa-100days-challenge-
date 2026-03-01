#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int n;

    // Read size
    scanf("%d", &n);

    int arr[n];

    // Read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];

    // Check all pairs
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    // Print result
    printf("%d %d\n", num1, num2);

    return 0;
}