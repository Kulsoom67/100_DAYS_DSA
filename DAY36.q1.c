QUES1: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;

    if(front == NULL) {
        front = rear = newnode;
        newnode->next = front;
    }
    else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    if(front == rear) {
        printf("Deleted element: %d\n", temp->data);
        front = rear = NULL;
    }
    else {
        printf("Deleted element: %d\n", temp->data);
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void display() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);

    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
