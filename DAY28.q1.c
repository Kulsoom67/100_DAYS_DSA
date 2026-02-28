QUES1:  Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createCLL(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }


    temp->next = head;

    return head;
}


void traverseCLL(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createCLL(n);
    traverseCLL(head);

    return 0;
}
