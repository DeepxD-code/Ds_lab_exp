#include <stdio.h>
#include <stdlib.h>

//structure for tree nodes
struct Node {
    int data;
    struct Node *left, *right;
};

             // Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


         // Pre-order traversal function V=>L=>R
void preorder(struct Node* node) {
    if (node == NULL)
        return;

        // Printing data of node
    printf("%d ", node->data);

        //first Traverse the left subtree
    preorder(node->left);

        //secondly Traverse the right subtree
    preorder(node->right);
}

     // In-order traversal function L=>V=>R
void inorder(struct Node* node) {
    if (node == NULL)
        return;

    //first Traverse the left subtree
    inorder(node->left);

    // Print data of node
    printf("%d ", node->data);

    //second Traverse the right subtree
    inorder(node->right);
}

      // Post-order traversal function L=>R=>V
void postorder(struct Node* node) {
    if (node == NULL)
        return;

        // Traverse the left subtree
    postorder(node->left);

        // Traverse the right subtree
    postorder(node->right);

        // Print data of node
    printf("%d ", node->data);
}


int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order traversal: ");
    preorder(root);
    
    printf("\n");
    
    printf("\nIn-order traversal: ");
    inorder(root);
    
    printf("\n");
    
    printf("\nPost-order traversal: ");
    postorder(root);

    return 0;
}