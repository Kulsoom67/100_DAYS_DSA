QUES1: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};


struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

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
        printf("%dx^%d", temp->coef, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    printf("Polynomial is:\n");
    display(poly);

    return 0;
}
