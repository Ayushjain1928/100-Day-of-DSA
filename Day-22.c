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

void traverse(struct Node* head) {
    struct Node* temp = head;

    printf("\n--- Linked List Output ---\n");

    while (temp != NULL) {
        if (temp != head)
            printf(" ");
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n--------------------------\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter %d integer value(s):\n", n);
    for (int i = 0; i < n; i++) {
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

    printf("\nTraversing the linked list...");
    traverse(head);

    printf("Total number of nodes: %d\n", countNodes(head));

    return 0;
}