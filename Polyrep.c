#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Term* next;
};

struct Polynomial {
    struct Term* head;
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(struct Polynomial* poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (poly->head == NULL) {
        poly->head = newTerm;
    } else {
        struct Term* temp = poly->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to print the polynomial
void printPolynomial(struct Polynomial* poly) {
    struct Term* temp = poly->head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial poly;
    poly.head = NULL;

    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        addTerm(&poly, coeff, exp);
    }

    printf("The polynomial is: ");
    printPolynomial(&poly);

    return 0;
}
