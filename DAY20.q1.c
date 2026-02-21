QUES1: Given an array of integers, count the number of subarrays whose sum is equal to zero.
  #include <stdio.h>

#define MAX 1000

int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0;
    int count = 0;


    int freq[2 * MAX + 1] = {0};
    freq[MAX] = 1;  

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        count += freq[prefixSum + MAX];

  
        freq[prefixSum + MAX]++;
    }

    return count;
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of zero-sum subarrays: %d\n",
           countZeroSumSubarrays(arr, n));

    return 0;
}
