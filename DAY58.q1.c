QUES1: Construct a binary tree from given preorder and inorder traversal arrays.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if(start > end)
        return NULL;

    struct Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if(start == end)
        return node;

    int inIndex = search(inorder, start, end, node->data);

    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

void printInorder(struct Node* root) {
    if(root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {

    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};

    int n = 5;
    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder of constructed tree:\n");
    printInorder(root);

    return 0;
}
