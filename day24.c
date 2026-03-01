
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

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = newNode(data);

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    // If list is empty
    if (head == NULL)
        return head;

    // If first node is key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for key
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    // If key found
    if (curr->next != NULL) {
        struct Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, key;
    struct Node* head = NULL;

    // Input list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    // Input key
    scanf("%d", &key);

    // Delete key
    head = deleteKey(head, key);

    // Print result
    printList(head);

    return 0;
}