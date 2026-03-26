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

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Case 1: head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("\nKey %d found at the HEAD and deleted.\n", key);
        return head;
    }

    // Case 2: search for the key in the rest of the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: key was not found
    if (temp == NULL) {
        printf("\nKey %d not found in the list.\n", key);
        return head;
    }

    // Key found: unlink the node and free memory
    prev->next = temp->next;
    printf("\nKey %d found and deleted.\n", key);
    free(temp);

    return head;
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

    printf("=== Delete First Occurrence of a Key ===\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = buildList(n);

    printf("\n--- Original List: ");
    traverse(head);

    printf("\nEnter the key to delete: ");
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printf("\n--- List After Deletion: ");
    traverse(head);

    return 0;
}
