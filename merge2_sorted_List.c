#include <stdio.h>
#include <stdlib.h>

//Def of a Node
struct Node {
    int data;
    struct Node* next;
};

//function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    if (head1->data <= head2->data) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return head;
}

//print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Insert elements into the first sorted linked list
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 5);

    // Insert elements into the second sorted linked list
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 6);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

//Function call
    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged List: ");
    printList(mergedHead);

    return 0;
}
