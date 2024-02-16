#include <stdio.h>
#define N 3 
int cq[N];
int f=-1;
int r=-1;
void enqueue(int x){
    if((r+1)%N==f){
        printf("Queue full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        cq[r]=x;
    }
    else{
        r=(r+1)%N;
        cq[r]=x;
    }
}
int dequeue(){
    int item;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
        return -999;
    }
    else if(f==r){
        item=cq[f];
        f=r=-1;
        return item;
    }
    else{
        item=cq[f];
        f=(f+1)%N;
        return item;
    }
}
void display(){
    int i;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
    }
    else{
        if(f<r){
    for(i=f;i<=r;i=(i+1)%N){
        printf("%d ",cq[i]);
    }
        }
    else if(f>=r){
        for(i=0;i<=r;i=(i+1)%N){
             printf("%d ",cq[i]);
        }
        for(i=f;i<=N-1;i=(i+1)%N){
            printf("%d ",cq[i]);
        }
    }
    }
}
void main(){
    int key,item;
    char choice;
    do{
        printf("Enter your choice\n1-enqueue\n2-dequeue\n3-display\n");
        scanf("%d",&key);
        switch(key){
            case 1:printf("Enter the number\n");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:item=dequeue();
                    printf("%d",item);
                break;
        case 3:display();
                break;
        default:printf("Invalid choice\n");
        
       }
    printf("\nDo you wish to continue?\n");
    scanf(" %c",&choice);
    }while(choice=='Y'||choice=='y');
}
