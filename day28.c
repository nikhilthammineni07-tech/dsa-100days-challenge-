#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Insert at end (circular)
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = newNode(data);

    // If list empty
    if (head == NULL) {
        head = temp;
        head->next = head;   // point to itself
        return head;
    }

    struct Node* p = head;
    while (p->next != head)
        p = p->next;

    p->next = temp;
    temp->next = head;   // make circular

    return head;
}

// Print circular list
void printList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // stop when back to head
}

int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printList(head);

    return 0;
}