#include <stdio.h>
#define N 20
int queue[N];
int f=-1;
int r=-1;
void enqueue(int x){
    if(r==N-1){
        printf("Queue full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        queue[r]=x;
    }
    else{
        queue[++r]=x;
    }
}
int dequeue(){
    int item;
    if(f==-1 && r==-1){
        printf("Queue empty\n");
        return -999;
    }
    else if(f==r){
        item=queue[f];
        f=r=-1;
        return item;
    }
    else{
        item=queue[f];
        f++;
        return item;
    }
}
void display(){
    int i;
    for(i=f;i<=r;i++){
        printf("%d ",queue[i]);
    }
}
void main(){
    char choice;
    int key,item;
    
    do{
       printf("Enter your choice\n1-enqueue\n2-dequeue\n3-display\n");
       scanf("%d",&key);
       switch(key){
           case 1:printf("Enter the element\n");
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
       printf("Do you wish to continue?\n");
       scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
}
