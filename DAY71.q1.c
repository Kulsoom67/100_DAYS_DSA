QUES1: Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index, i = 0;

    while (i < SIZE) {
        index = (hash(key) + i * i) % SIZE;

        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }

    printf("Hash Table is Full\n");
}

int search(int key) {
    int index, i = 0;

    while (i < SIZE) {
        index = (hash(key) + i * i) % SIZE;

        if (hashTable[index] == key) {
            return index;
        }

        if (hashTable[index] == EMPTY) {
            return -1;
        }

        i++;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    int key = 43;
    int result = search(key);

    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);

    return 0;
}
