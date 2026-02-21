QUES1: Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void closestToZero(int arr[], int n) {
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int num1 = 0, num2 = 0;

    qsort(arr, n, sizeof(int), compare);

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements closest to zero: %d and %d\n", num1, num2);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    closestToZero(arr, n);

    return 0;
}
