#include <stdio.h>
#include <stdlib.h>
//program to generate singly linked list, insert at beginning and Printing the list.

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //creates node of size of structure
    newNode->data = data;
    newNode->next = NULL;
    return newNode;                                                    //Returns new node to the function call line.
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;                                             //Constantly updates and relinks the head to the linked list to inser at beginning
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 7);
    
    printf("Linked list:\n");
    printList(head);
     
    return 0; 
}