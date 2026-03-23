#include <stdio.h>

int main() {
    int n, pos, x;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("enter the element of array\n");
    for (int i = 0; i < n; i++) {
        printf("%d:" , i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the position :");
    scanf("%d", &pos);
    printf("\nEnter the value : ");
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}