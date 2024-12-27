#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int value) {
    if (node == NULL) return newNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values to insert into the BST: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("In-order traversal of the binary search tree:\n");
    inOrder(root);

    return 0;
}
