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

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
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
    int n, key;

    printf("=== Count Occurrences of an Element ===\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = buildList(n);

    printf("\n--- Linked List: ");
    traverse(head);

    printf("\nEnter the key to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);

    printf("\n--- Key %d appears %d time(s) in the list.\n", key, result);

    return 0;
}
