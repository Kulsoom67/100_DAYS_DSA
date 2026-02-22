QUES1: Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int main() {
    struct Node *head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 10);
    insertEnd(&head, 15);
    insertEnd(&head, 20);

    printf("Number of nodes = %d\n", countNodes(head));

    return 0;
}
