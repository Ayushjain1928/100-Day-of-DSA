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

int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
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

int findIntersection(struct Node* l1, struct Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Advance the pointer of the longer list
    while (len1 > len2) {
        l1 = l1->next;
        len1--;
    }

    while (len2 > len1) {
        l2 = l2->next;
        len2--;
    }

    // Traverse both lists simultaneously
    while (l1 != NULL && l2 != NULL) {
        if (l1->data == l2->data)
            return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }

    return -1;
}

int main() {
    int n, m;

    printf("=== Find Intersection Point of Two Linked Lists ===\n\n");

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

    int result = findIntersection(list1, list2);

    if (result == -1)
        printf("\nNo Intersection\n");
    else
        printf("\nIntersection Point: %d\n", result);

    return 0;
}