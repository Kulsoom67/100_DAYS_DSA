QUES1: Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* queue[MAX];
int front = 0, rear = -1;


void enqueue(Node* node) {
    queue[++rear] = node;
}


Node* dequeue() {
    return queue[front++];
}


Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* current = dequeue();


        if (i < n) {
            current->left = createNode(arr[i++]);
            enqueue(current->left);
        }


        if (i < n) {
            current->right = createNode(arr[i++]);
            enqueue(current->right);
        }
    }

    return root;
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}
