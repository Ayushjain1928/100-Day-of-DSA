#include <stdio.h>
#include <stdlib.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    int sum = 0;

    // Hash map using array (range assumption)
    int hash[20001] = {0};  // supports sums from -10000 to 10000
    int offset = 10000;

    hash[offset] = 1; // sum = 0 already seen

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum >= -10000 && sum <= 10000) {
            count += hash[sum + offset];
            hash[sum + offset]++;
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);

    printf("\nNumber of subarrays with sum = 0: %d\n", result);

    return 0;
}