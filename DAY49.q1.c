QUES1: Implement the solution for this problem.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n, val;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int leftIndex, rightIndex;
        scanf("%d %d", &leftIndex, &rightIndex);

        if (leftIndex != -1)
            nodes[i]->left = nodes[leftIndex];

        if (rightIndex != -1)
            nodes[i]->right = nodes[rightIndex];
    }

    int result = countLeafNodes(nodes[0]);
    printf("%d\n", result);

    return 0;
}
