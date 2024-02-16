#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff, expo;
    struct node* link;
} Node;

Node* readpoly() {
    Node *newnode, *ptr, *header;
    header = (Node*)malloc(sizeof(Node));
    header->link = NULL;
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        newnode = (Node*)malloc(sizeof(Node));
        printf("Enter the coefficient and exponent in descending order: ");
        scanf("%d%d", &newnode->coeff, &newnode->expo);
        newnode->link = NULL;
        if (header->link == NULL) {
            header->link = newnode;
            ptr = newnode;
        } else {
            ptr->link = newnode;
            ptr = ptr->link;
        }
    }
    return header;
}

void display(Node* header) {
    Node* ptr = header->link;
    while (ptr != NULL) {
        printf("%dx^%d ", ptr->coeff, ptr->expo);
        if (ptr->link != NULL) {
            printf("+ ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}

Node* addTerm(Node* header, int coeff, int expo) {
    Node *ptr = header->link, *prev = header, *newnode;

    while (ptr != NULL && ptr->expo > expo) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr != NULL && ptr->expo == expo) {
        // Term with the same exponent already exists, add coefficients
        ptr->coeff += coeff;
    } else {
        // Create a new term
        newnode = (Node*)malloc(sizeof(Node));
        newnode->coeff = coeff;
        newnode->expo = expo;
        newnode->link = ptr;
        prev->link = newnode;
    }

    return header;
}


Node* MulPoly(Node* Pheader, Node* Qheader) {
    Node *Pptr, *Qptr, *header, *Rptr;

    header = (Node*)malloc(sizeof(Node));
    header->link = NULL;
    Rptr = header;

    Pptr = Pheader->link;

    while (Pptr != NULL) {
        Qptr = Qheader->link;

        while (Qptr != NULL) {
            // Multiply coefficients and add exponents
            header = addTerm(header, Pptr->coeff * Qptr->coeff, Pptr->expo + Qptr->expo);
            Qptr = Qptr->link;
        }

        Pptr = Pptr->link;
    }

    return header;
}

int main() {
    Node *Pheader, *Qheader, *Rheader;

    printf("Enter details of the first polynomial:\n");
    Pheader = readpoly();

    printf("Enter details of the second polynomial:\n");
    Qheader = readpoly();

    printf("First polynomial:\n");
    display(Pheader);

    printf("Second polynomial:\n");
    display(Qheader);

    Rheader = MulPoly(Pheader, Qheader);

    printf("Product of polynomials:\n");
    display(Rheader);



    return 0;
}
