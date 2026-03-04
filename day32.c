#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m;

    // Read number of elements to push
    scanf("%d", &n);

    // Push n elements
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        if(top == MAX - 1) {
            printf("Stack Overflow\n");
            return 0;
        }

        top++;
        stack[top] = value;
    }

    // Number of pops
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            return 0;
        }
        top--;
    }

    // Print remaining stack (top to bottom)
    if(top == -1) {
        printf("Stack is Empty");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}