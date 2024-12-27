#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Initial linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Initial Linked List: ");
    printList(head);

    // Deletion operations
    deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    printList(head);

    deleteAtEnd(&head);
    printf("After deleting at end: ");
    printList(head);

    deleteNode(&head, 2);
    printf("After deleting node with value 2: ");
    printList(head);

    return 0;
}

