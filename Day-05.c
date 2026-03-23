#include <stdio.h>

int main() {
    int p, q;

    printf("Enter number of entries in first log: ");
    scanf("%d", &p);

    int a[p];
    printf("Enter %d sorted values for first log: ", p);
    for(int i = 0; i < p; i++)
        scanf("%d", &a[i]);

    printf("Enter number of entries in second log: ");
    scanf("%d", &q);

    int b[q];
    printf("Enter %d sorted values for second log: ", q);
    for(int i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0;

    printf("Merged chronological log: ");

    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
} 