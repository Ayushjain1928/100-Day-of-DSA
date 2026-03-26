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

struct Node* buildCircularList(int size) {
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
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    return head;
}

void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    printf("\n--- Circular Linked List: ");
    do {
        if (temp != head)
            printf(" ");
        printf("%d", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
    printf("--- (Last node points back to: %d)\n", head->data);
}

int main() {
    int n;

    printf("=== Circular Linked List Creation and Traversal ===\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = buildCircularList(n);

    traverse(head);

    return 0;
}
