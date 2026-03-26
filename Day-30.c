#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp   = exp;
    newNode->next  = NULL;
    return newNode;
}

struct Node* buildPolynomial(int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter %d term(s) (coefficient and exponent):\n", size);
    for (int i = 0; i < size; i++) {
        int coeff, exp;
        printf("  Term [%d] - Coefficient: ", i + 1);
        scanf("%d", &coeff);
        printf("  Term [%d] - Exponent   : ", i + 1);
        scanf("%d", &exp);

        struct Node* newNode = createNode(coeff, exp);

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

void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    printf("\n--- Polynomial: ");
    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);               // constant term
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);              // linear term
        else
            printf("%dx^%d", temp->coeff, temp->exp); // higher degree term

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("=== Polynomial Using Linked List ===\n\n");

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    struct Node* head = buildPolynomial(n);

    printPolynomial(head);

    return 0;
}