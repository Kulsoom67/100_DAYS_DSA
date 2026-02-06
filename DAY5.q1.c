QUES1:  A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
  #include <stdio.h>

void mergeLogs(int log1[], int n, int log2[], int m, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (log1[i] <= log2[j]) {
            result[k++] = log1[i++];
        } else {
            result[k++] = log2[j++];
        }
    }
    while (i < n) {
        result[k++] = log1[i++];
    }

    while (j < m) {
        result[k++] = log2[j++];
    }
}

int main() {
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 6, 9};

    int n = 4, m = 4;
    int merged[8];

    mergeLogs(log1, n, log2, m, merged);

    printf("Merged Chronological Log:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
