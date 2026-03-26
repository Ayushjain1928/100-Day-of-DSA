#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
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
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void traverseForward(struct Node* head) {
    struct Node* temp = head;

    printf("\n--- Forward Traversal: ");
    while (temp != NULL) {
        if (temp != head)
            printf(" ");
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* head) {
    struct Node* tail = head;

    while (tail->next != NULL)
        tail = tail->next;

    printf("--- Backward Traversal: ");
    while (tail != NULL) {
        if (tail->next != NULL)
            printf(" ");
        printf("%d", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    int n;

    printf("=== Doubly Linked List Insertion and Traversal ===\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = buildList(n);

    traverseForward(head);
    traverseBackward(head);

    return 0;
}