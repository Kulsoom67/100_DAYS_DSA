QUES1: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int n1 = 5, n2 = 15;

    struct Node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);

    return 0;
}
