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

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || k == 0)
        return head;

    int n = getLength(head);
    k = k % n;   // if k > n
    if (k == 0)
        return head;

    struct Node* temp = head;
    
    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;  // Make circular

    // Move to (n - k)th node
    int steps = n - k;
    temp = head;
    for (int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;  // New head
    temp->next = NULL;  // Break circular link

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
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}