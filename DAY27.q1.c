QUES1: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}


struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);


    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }


    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}


int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;


    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 5);


    head2 = createNode(9);
    head2->next = head1->next->next->next; 

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection != NULL)
        printf("Intersection Point Data: %d\n", intersection->data);
    else
        printf("No Intersection Found\n");

    return 0;
}
