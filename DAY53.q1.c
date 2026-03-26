QUES1: Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct QueueNode {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct QueueNode queue[MAX];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QueueNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void verticalOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    int map[2000][MAX];
    int count[2000] = {0};
    int offset = 1000;

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QueueNode temp = dequeue();
        struct TreeNode* node = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = node->val;

        if (node->left)
            enqueue(node->left, temp.hd - 1);

        if (node->right)
            enqueue(node->right, temp.hd + 1);
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}
