#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
};

// create a new node for doubly linked list
struct DoublyNode* createDoublyNode(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
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

//Print the doubly linked list
void printDoublyList(struct DoublyNode* head) {
    struct DoublyNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// reverse the doubly linked list
void reverseDoublyList(struct DoublyNode** head) {
    struct DoublyNode* temp = NULL;
    struct DoublyNode* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct DoublyNode* headDoubly = NULL;

    
    insertAtEndDoubly(&headDoubly, 1);
    insertAtEndDoubly(&headDoubly, 2);
    insertAtEndDoubly(&headDoubly, 3);

    printf("Original Doubly Linked List: ");
    printDoublyList(headDoubly);

    // Reverse the doubly linked list
    reverseDoublyList(&headDoubly);

    printf("Reversed Doubly Linked List: ");
    printDoublyList(headDoubly);

    return 0;
}
