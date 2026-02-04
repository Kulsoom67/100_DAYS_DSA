QUES1: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    reverseArray(arr, n);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
