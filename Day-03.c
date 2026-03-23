#include <stdio.h>

int main() {
    int n, k, i, found = -1, comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}