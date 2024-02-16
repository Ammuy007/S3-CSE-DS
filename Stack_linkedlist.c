#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;
Node* header,*ptr,*newnode,*top=NULL;
void push(int x){
    newnode=(Node*)malloc(sizeof(Node));
    if(header->link==NULL){
        header->link=newnode;
        newnode->data=x;
        newnode->link=top;
        top=newnode;
    }
    else{
        newnode->data=x;
        newnode->link=top;
        top=newnode;
    }
}
int pop(){
    int item;
    if(top==NULL){
        printf("Stack empty\n");
        return -999;
    }
    else{
        ptr=top->link;
        item=top->data;
        header->link=ptr;
        free(top);
        top=ptr;
        return item;
    }
}
int display(){
    ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
return 0;
}
void main(){
    int item;
    header=(Node*)malloc(sizeof(Node));
    header->data=0;
    header->link=NULL;
    push(4);
    push(9);
    push(10);
    printf("%d ",pop());
    push(2);
    printf("The content is\n");
    display();
}
