QUES1: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}


int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}


int evaluatePostfix(char exp[]) {
    int i = 0;
    int op1, op2;

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        else {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    return pop();
}

int main() {
    char postfix[100];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
  
