QUES1: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int count = 1;
    struct Node* temp = head;

  
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }


    temp->next = head;

    k = k % count;
    int steps = count - k;

    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    struct Node* head = NULL;
    int n, x, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original List:\n");
    display(head);

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    display(head);

    return 0;
}
