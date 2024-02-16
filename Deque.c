#include <stdio.h>
#define N 4
int dq[N];
int f=-1;
int r=-1;
void efront(int x){
    if(f==r+1||(f==0&&r==N-1)){
        printf("Queue full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        dq[f]=x;
    }
    else if(f==0){
        f=N-1;
        dq[f]=x;
    }
    else{
        f--;
        dq[f]=x;
    }
}
int dfront(){
    int item;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
        return -999;
    }
    else if(f==r){
        item=dq[f];
        f=r=-1;
        return item;
    }
    else if(f==N-1){
        item=dq[f];
        f=0;
        return item;
    }
    else{
        item=dq[f];
        f++;
        return item;
    }
}
void erear(int x){
    if(f==r+1||(f==0&&r==N-1)){
        printf("Queue full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        dq[r]=x;
    }
    else if(r==N-1){
        r=0;
        dq[r]=x;
    }
    else{
        dq[++r]=x;
    }
}
int drear(){
    int item;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
    }
    else if(f==r){
        item=dq[r];
        f=r=-1;
        return item;
    }
    else if(r==0){
        item=dq[r];
        r=N-1;
        return item;
    }
    else{
        item=dq[r];
        r--;
        return item;
    }
}
void display(){
    int i;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
    }
    else{
        for (i = f; i != r; i = (i + 1) % N) {
            printf("%d ", dq[i]);
        }
        printf("%d\n", dq[i]);
    }
}
void main(){
    int key,item;
    char choice;
    do{
        printf("Enter your choice\n1-enqueue at front \n2-dequeue at front\n3-enqueue at rear\n4-dequeue at rear\n5-display\n");
        scanf("%d",&key);
        switch(key){
            case 1:printf("Enter the number\n");
                scanf("%d",&item);
                efront(item);
                break;
            case 2:item=dfront();
                    printf("%d",item);
                break;
            case 3:printf("Enter the number\n");
                scanf("%d",&item);
                erear(item);
                break;
            case 4:item=drear();
                    printf("%d",item);
                break;
        case 5:display();
                break;
        default:printf("Invalid choice\n");
        
       }
    printf("\nDo you wish to continue?\n");
    scanf(" %c",&choice);
    }while(choice=='Y'||choice=='y');
}
