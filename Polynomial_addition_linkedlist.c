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

Node* Addpoly(Node* Pheader, Node* Qheader) {
    Node *Rheader, *Rptr, *Pptr, *Qptr;
    Rheader = (Node*)malloc(sizeof(Node));
    Rheader->link = NULL;
    Rptr = Rheader;
    Pptr = Pheader->link;
    Qptr = Qheader->link;

    while (Pptr != NULL && Qptr != NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->link = NULL;
        if (Pptr->expo > Qptr->expo) {
            newnode->coeff = Pptr->coeff;
            newnode->expo = Pptr->expo;
            Pptr = Pptr->link;
        } else if (Pptr->expo < Qptr->expo) {
            newnode->coeff = Qptr->coeff;
            newnode->expo = Qptr->expo;
            Qptr = Qptr->link;
        } else {
            newnode->coeff = Pptr->coeff + Qptr->coeff;
            newnode->expo = Pptr->expo;
            Pptr = Pptr->link;
            Qptr = Qptr->link;
        }

        if (newnode->coeff != 0) {
            Rptr->link = newnode;
            Rptr = Rptr->link;
        }
    }

    while (Pptr != NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->link = NULL;
        newnode->coeff = Pptr->coeff;
        newnode->expo = Pptr->expo;
        Pptr = Pptr->link;
        Rptr->link = newnode;
        Rptr = Rptr->link;
    }

    while (Qptr != NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->link = NULL;
        newnode->coeff = Qptr->coeff;
        newnode->expo = Qptr->expo;
        Qptr = Qptr->link;
        Rptr->link = newnode;
        Rptr = Rptr->link;
    }

    return Rheader;
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

    Rheader = Addpoly(Pheader, Qheader);

    printf("Sum of polynomials:\n");
    display(Rheader);

    return 0;
}
