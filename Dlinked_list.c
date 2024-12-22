#include <stdio.h>
#include <stdlib.h>

//definition of a Node
struct DoublyNode {
    int data;
    struct DoublyNode* prev;                //pointer for previous link 
    struct DoublyNode* next;                //for next node 
};

// Function to create a new node for doubly linked list
struct DoublyNode* createDoublyNode(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//fn. to insert a node at the end of the doubly linked list
void insertAtEndDoubly(struct DoublyNode** head, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct DoublyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fn. to print the doubly linked list
void printDoublyList(struct DoublyNode* head) {
    struct DoublyNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct DoublyNode* headDoubly = NULL;

    
    insertAtEndDoubly(&headDoubly, 1);
    insertAtEndDoubly(&headDoubly, 2);
    insertAtEndDoubly(&headDoubly, 3);                  //Insertion in the list
    insertAtEndDoubly(&headDoubly, 0);                  //Insertion in the list
    insertAtEndDoubly(&headDoubly, 8);                  //Insertion in the list

    
    printf("Doubly Linked List: ");              
    printDoublyList(headDoubly);                 //Print the doubly linked list

    return 0;
}
