#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;

    for (int i = 0; i < m && i < n; i++) {
        sum += arr[i][i];
    }

    printf("Sum of primary diagonal elements: %d", sum);

    return 0;
}