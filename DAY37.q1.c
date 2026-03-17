QUES1: Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq[size++] = value;
}

int delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    int minIndex = 0;


    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    int value = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return value;
}


void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(5);
    insert(2);
    insert(8);
    insert(1);

    display();

    printf("Deleted: %d\n", delete());
    display();

    printf("Deleted: %d\n", delete());
    display();

    return 0;
}
