#include <stdio.h>

int main() {
    int m, n;
    int a[100][100];
    int i, j;
    int isSymmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Check if matrix is square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Input matrix elements
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check symmetric condition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    // Print result
    if (isSymmetric == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
