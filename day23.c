#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Merge two sorted lists
struct Node* merge(struct Node* l1, struct Node* l2) {
    struct Node dummy;          // temporary node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

// Print list
void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL, *temp;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = newNode(x);
        temp->next = l1;
        l1 = temp;
    }

    // Reverse first list (to keep order correct)
    struct Node *prev = NULL, *curr = l1, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l1 = prev;

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        temp = newNode(x);
        temp->next = l2;
        l2 = temp;
    }

    // Reverse second list
    prev = NULL; curr = l2;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l2 = prev;

    // Merge and print
    struct Node* result = merge(l1, l2);
    print(result);

    return 0;
}