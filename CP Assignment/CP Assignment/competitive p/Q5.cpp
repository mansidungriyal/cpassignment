#include <stdio.h>
int lower_bound(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}
int upper_bound(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}
int is_present(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the number to search: ");
    scanf("%d", &x);
    int lower = lower_bound(arr, n, x);
    if (lower != -1) {
        printf("Lower bound of %d: %d\n", x, arr[lower]);
    } else {
        printf("No element is greater or equal to %d\n", x);
    }
    int upper = upper_bound(arr, n, x);
    if (upper != -1) {
        printf("Upper bound of %d: %d\n", x, arr[upper]);
    } else {
        printf("No element is greater than %d\n", x);
    }
    if (is_present(arr, n, x)) {
        printf("%d is present in the array\n", x);
    } else {
        printf("%d is not present in the array\n", x);
    }

    return 0;
}
