QUES1: Implement a Queue using a linked list supporting enqueue and dequeue operations.
  #include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}


void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    Node* temp = front;
    printf("Dequeued: %d\n", temp->data);

    front = front->next;

    if (front == NULL)   
        rear = NULL;

    free(temp);
}


void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
