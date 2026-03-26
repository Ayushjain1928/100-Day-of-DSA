#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter %d integer value(s):\n", size);
    for (int i = 0; i < size; i++) {
        int val;
        printf("  Element [%d]: ", i + 1);
        scanf("%d", &val);

        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (head == NULL || k % n == 0)
        return head;

    k = k % n;   // handle k greater than list length

    // Step 1: Connect last node to head (make circular)
    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;

    // Step 2: Find the new tail at (n - k - 1)th node
    int steps = n - k - 1;
    struct Node* newTail = head;
    for (int i = 0; i < steps; i++)
        newTail = newTail->next;

    // Step 3: New head is the node after new tail
    struct Node* newHead = newTail->next;
    newTail->next = NULL;   // break the circle

    return newHead;
}

void traverse(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp != head)
            printf(" ");
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;

    printf("=== Rotate Linked List Right by K Places ===\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = buildList(n);

    printf("\n--- Original List: ");
    traverse(head);

    printf("\nEnter the value of k: ");
    scanf("%d", &k);

    head = rotateRight(head, k, n);

    printf("\n--- Rotated List: ");
    traverse(head);

    return 0;
}