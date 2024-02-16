#include <stdio.h>

typedef struct poly {
    int expo;
    float coeff;
}p1[10], p2[10], p3[10];


void readPoly(struct poly[]);
void printPoly(struct poly[], int n);
int addPoly(struct poly[], struct poly[], struct poly[], int n, int m);

int main() {
    int n, t3, t1,t2;
    
    t1=readPoly(p1);
    printf("The first polynomial is: ");
    printPoly(p1, t1);
    printf("\n");

   
    t2=readPoly(p2);
    printf("The second polynomial is: ");
    printPoly(p2, t2);
    printf("\n");

    t3 = addPoly(p1, p2, p3, t1, t2);
    printf("Result is: ");
    printPoly(p3, t3);
    printf("\n");

    return 0;
}


int readPoly(struct poly p[10]) {
    int t1,i;
    printf("Enter the number of terms\n");
    scanf("%d",&t1);
    for (i = 0; i < t1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &p[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t1;
}

void printPoly(struct poly p[10], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%.2fx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%.2fx^%d", p[n - 1].coeff, p[n - 1].expo);
}

int addPoly(struct poly p1[10], struct poly p2[10], struct poly p3[10], int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            k++;
            i++;
            j++;
        } else if (p1[i].expo < p2[j].expo) {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff;
            k++;
            i++;
        } else {
            p3[k].expo = p2[j].expo;
            p3[k].coeff = p2[j].coeff;
            k++;
            j++;
        }
    }
    while (i < m) {
        p3[k].expo = p1[i].expo;
        p3[k].coeff = p1[i].coeff;
        k++;
        i++;
    }
    while (j < n) {
        p3[k].expo = p2[j].expo;
        p3[k].coeff = p2[j].coeff;
        k++;
        j++;
    }
    return k;
}
