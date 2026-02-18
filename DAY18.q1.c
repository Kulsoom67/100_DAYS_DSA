QUES1: Given an array of integers, rotate the array to the right by k positions.
  #include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {
    if (n == 0)
        return;

    k = k % n;   


    reverse(arr, 0, n - 1);

    reverse(arr, 0, k - 1);

   
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    rotateRight(arr, n, k);

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
