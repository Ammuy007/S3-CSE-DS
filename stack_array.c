#define N 20
#include <stdio.h>
int stack[N];
int top=-1;
void push(int x){
    if(top==N-1){
        printf("Stack full\n");
    }
    else{
        stack[++top]=x;
    }
}
int pop(){
    int item;
    if(top==-1){
        printf("Stack empty\n");
    }
    else{
        item=stack[top];
        top--;
        return item;
    }
}
void display(){
    int i;
    if(top==-1){
        printf("Empty\n");
    }
    else{
        for(i=0;i<=top;i++){
        printf("%d ",stack[i]);
        
        }
    }
    printf("\n");
}
void main(){
    int key;
    char choice;
    do{
        int item,x;
        printf("\nEnter your choice\n1-push\n2-pop\n3-display\n");
        scanf("%d",&key);
        switch(key){
            case 1:printf("Enter the number to be inserted\n");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:item=pop();
                    printf("The deleted number is %d \n",item);
                    break;
            case 3:display();
                    break;
            default:printf("Invalid option\n");
        }
        printf("Do you wish to continue?\n");
        scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
}
