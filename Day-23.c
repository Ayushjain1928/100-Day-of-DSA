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

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        int val;

        if (l1->data <= l2->data) {
            val = l1->data;
            l1 = l1->next;
        } else {
            val = l2->data;
            l2 = l2->next;
        }

        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (l1 != NULL) {
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

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
    int n, m;

    printf("=== Merge Two Sorted Linked Lists ===\n\n");

    printf("Enter the number of elements in List 1: ");
    scanf("%d", &n);
    struct Node* list1 = buildList(n);

    printf("\nEnter the number of elements in List 2: ");
    scanf("%d", &m);
    struct Node* list2 = buildList(m);

    printf("\n--- List 1: ");
    traverse(list1);

    printf("--- List 2: ");
    traverse(list2);

    struct Node* merged = mergeSorted(list1, list2);

    printf("\n--- Merged List: ");
    traverse(merged);

    return 0;
}