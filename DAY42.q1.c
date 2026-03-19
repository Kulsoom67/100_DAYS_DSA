QUES1: Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100


int queue[MAX];
int front = 0, rear = -1;


int stack[MAX];
int top = -1;


void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = val;
}


int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}


void push(int val) {
    stack[++top] = val;
}


int pop() {
    return stack[top--];
}


void reverseQueue() {

    while (front <= rear) {
        push(dequeue());
    }

    front = 0;
    rear = -1;


    while (top != -1) {
        enqueue(pop());
    }
}


void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original ");
    display();

    reverseQueue();

    printf("Reversed ");
    display();

    return 0;
}
