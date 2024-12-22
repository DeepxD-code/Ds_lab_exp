#include <stdio.h>
#include <stdlib.h>

// Definition of a Node 
struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
};

//fn. to create a new node for doubly circular linked list
struct DoublyNode* createDoublyNode(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// fn. to insert a node at the end of the doubly circular linked list
void insertAtEndDoublyCircular(struct DoublyNode** head, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
    } else {
        struct DoublyNode* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

//print the doubly circular linked list
void printDoublyCircularList(struct DoublyNode* head) {
    if (head == NULL) return;
    struct DoublyNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct DoublyNode* headDoublyCircular = NULL;

    // Insert elements into the doubly circular linked list
    insertAtEndDoublyCircular(&headDoublyCircular, 4);
    insertAtEndDoublyCircular(&headDoublyCircular, 5);
    insertAtEndDoublyCircular(&headDoublyCircular, 6);
    insertAtEndDoublyCircular(&headDoublyCircular, 9);
    insertAtEndDoublyCircular(&headDoublyCircular, 3);
    insertAtEndDoublyCircular(&headDoublyCircular, 0);

    printf("Doubly Circular Linked List: ");
    printDoublyCircularList(headDoublyCircular);                // Print the doubly circular linked list

    return 0;
}
