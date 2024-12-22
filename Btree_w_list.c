#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//insert a node in the binary tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    } else {
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}



// function  thts displays nodes at each level
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    //queue creation for level order traversal
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0, rear = 0;

    // enqueue root
    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;

        //loop prints nodes at the current level
        while (nodeCount > 0) {
            struct Node* node = queue[front++];

            printf("%d ", node->data);                  //deque process

            //enqueue left child
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }

            //enqueue right child
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }

            nodeCount--;
        }
        printf("\n"); //for new level
    }

    free(queue);
}

int main() {
    struct Node* root = NULL;

    //create the binary tree
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);

    
    printf("Level Order Traversal (by levels):\n");
    printLevelOrder(root);

    return 0;
}
