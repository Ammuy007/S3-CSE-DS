#include <stdio.h>
typedef struct{
    int row;
    int col;
    int value
}term;
term a[10];term b[10];
void createSparse(int A[10][10],int m,int n){
    int i,j,k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(A[i][j]!=0){
                a[k].row=i;
                a[k].col=j;
                a[k].value=A[i][j];
                k++;
            }
        }
    }
    a[0].value=k-1;
    a[0].row=m;
    a[0].col=n;
}
void display(term mat[]){
    int k=mat[0].value;
    int i;
    for(i=0;i<=k;i++){
        printf("%d %d %d\n",mat[i].row,mat[i].col,mat[i].value);
    }
}
void transpose(term a[]){
    int i,j;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=a[0].value;
    int q=1,n=a[0].value;
    if(n>0){
        for(i=0;i<a[0].col;i++){
            for(j=1;j<=n;j++){
                if(a[j].col==i){
                    b[q].value=a[j].value;
                    b[q].row=a[j].col;
                    b[q].col=a[j].row;
                    q++;
                }
            }
        }
    }

    
    
}
int main(){
    int m,n,i,j;
    int A[10][10],B[10][10];
    printf("Enter the order of matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    createSparse(A,m,n);
    printf("SParse\n");
    display(a);
    transpose(a);
    printf("transpose\n");
    display(b);
    return 0;
}
