QUES1: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
  #include <stdio.h>

int main() {
    int n, k, i, found = 0, count = 0;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        count++;                 
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Key found at position %d\n", i + 1);
    else
        printf("Key not found\n");

    printf("Number of comparisons: %d\n", count);

    return 0;
}
