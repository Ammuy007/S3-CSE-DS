//Multiple Stack
#include <stdio.h>
#define Max 20
int stack[Max];
int top1=-1,top2=Max;
void push(int stacknum,int x){
    if(stacknum==1){
        if(top1==top2-1){
            printf("Stack full\n");
        }
        else{
            stack[++top1]=x;
        }
    }
    else if(stacknum==2){
        if(top2==top1+1){
            printf("Stack full");
        }
        else{
            stack[--top2]=x;
        }
    }
}
int pop(int stacknum){
    if(stacknum==1){
        if(top1==-1){
            printf("Stack empty\n");
            return -999;
        }
        return stack[top1--];
    }
    else if(stacknum==2){
        if(top2==Max){
            printf("Stack empty\n");
            return -999;
        }
        return stack[top2++];
        
    }
}
void display(int stacknum){
    int i;
    if(stacknum==1){
        if(top1==-1){
            printf("Stack empty\n");
        }
        else{
            printf("The elements are\n");
            for(i=0;i<=top1;i++){
                printf("%d",stack[i]);
            }
        }
        
    }
    else if(stacknum==2){
        if(top2==Max){
            printf("Stack empty\n");
        }
        else{
            printf("The elements are\n");
            for(i=Max-1;i>=top2;i--){
                printf("%d",stack[i]);
            }
    }
}
}
void main(){
    char choice;
    int key,stacknum;
    int item;
    printf("Enter stacknum\n");
    scanf("%d",&stacknum);
    do{
        printf("\nEnter your choice\n1-Push\n2-Pop\n3-Change stack number\n4-Display\n");
        scanf("%d",&key);
        switch(key){
            case 1:printf("Enter the number\n");
                    scanf("%d",&item);
                    push(stacknum,item);
                    break;
            case 2:item=pop(stacknum);
                    printf("%d ",item);
                    break;
            case 3:printf("Enter the stack number(1/2)");
                    scanf("%d",&stacknum);
                    break;
            case 4:display(stacknum);
                    break;
            default:printf("Invalid choice\n");
        }
        printf("\nDo you wish to continue?(y/Y)\n");
        scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
}
