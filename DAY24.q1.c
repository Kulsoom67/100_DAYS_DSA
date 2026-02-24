QUES1: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* temp;


    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }


    if (head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }


    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next != NULL) {
        temp = current->next;
        current->next = temp->next;
        free(temp);
    } else {
        printf("Key not found\n");
    }

    return head;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(20);
    head->next->next->next->next = createNode(40);

    printf("Original List:\n");
    printList(head);

    head = deleteFirstOccurrence(head, 20);

    printf("After deleting first occurrence of 20:\n");
    printList(head);

    return 0;
}
