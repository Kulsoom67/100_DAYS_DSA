QUES1: Check whether a given binary tree satisfies the Min-Heap property.
  #include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countNodes(struct Node* root){
    if(root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isComplete(struct Node* root, int index, int total){
    if(root == NULL)
        return 1;

    if(index >= total)
        return 0;

    return isComplete(root->left, 2*index+1, total) &&
           isComplete(root->right, 2*index+2, total);
}

int isHeap(struct Node* root){
    if(root->left == NULL && root->right == NULL)
        return 1;

    if(root->right == NULL){
        return root->data <= root->left->data;
    }

    if(root->data <= root->left->data &&
       root->data <= root->right->data)
        return isHeap(root->left) && isHeap(root->right);

    return 0;
}

int isMinHeap(struct Node* root){
    int total = countNodes(root);

    if(isComplete(root,0,total) && isHeap(root))
        return 1;

    return 0;
}

int main(){

    struct Node* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    if(isMinHeap(root))
        printf("Tree satisfies Min Heap property\n");
    else
        printf("Tree does not satisfy Min Heap property\n");

    return 0;
}
