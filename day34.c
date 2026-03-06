#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char exp[]) {
    int i = 0;

    while(exp[i] != '\0') {

        if(exp[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(exp[i])) {
            int num = 0;
            while(isdigit(exp[i])) {
                num = num*10 + (exp[i]-'0');
                i++;
            }
            push(num);
        }
        else {
            int b = pop();
            int a = pop();
            int res;

            if(exp[i] == '+') res = a + b;
            else if(exp[i] == '-') res = a - b;
            else if(exp[i] == '*') res = a * b;
            else if(exp[i] == '/') res = a / b;

            push(res);
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);
    printf("%d\n", result);

    return 0;
}