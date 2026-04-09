QUES1: Construct a binary tree from given inorder and postorder traversal arrays.
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

struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if(start > end)
        return NULL;

    struct Node* node = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if(start == end)
        return node;

    int inIndex = search(inorder, start, end, node->data);

    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

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

    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    int n = 5;
    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder of constructed tree:\n");
    printInorder(root);

    return 0;
}
