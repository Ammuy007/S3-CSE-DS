#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;
Node* header1,*header,*newnode,*front=NULL,*rear=NULL,*top=NULL;
void enqueue(int x){
    newnode=(Node*)malloc(sizeof(Node));
    if(header->link==NULL){
        front=rear=newnode;
        newnode->data=x;
        header->link=newnode;
        newnode->link=NULL;
    }
    else{
        newnode->link=NULL;
        newnode->data=x;
        rear->link=newnode;
        rear=newnode;
    }
}
int dequeue(){
    Node* ptr;
    int item;
    if(front==NULL && rear==NULL){
        printf("List empty\n");
        return -999;
    }
    else{
        ptr=front->link;
        header->link=ptr;
        item=front->data;
        free(front);
        front=ptr;
        return item;
    }
}
void display(){
    Node* ptr=front;
    if(front==NULL){
        printf("List empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
}
void push(int a){
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=a;
    
    if(header1->link==NULL){
        header1->link=newnode;
        newnode->link=top;
        top=newnode;
    }
    else{
        newnode->link=top;
        top=newnode;
    }
}
int pop(){
    int item;
    Node* ptr;
    if(top==NULL){
        printf("List empty\n");
        return -999;
    }
    else{
        item=top->data;
        ptr=top->link;
        header1->link=ptr;
        free(top);
        top=ptr;
        return item;
    }
}
void reverse(){
    int a,b;
    while(front!=NULL){
        a=dequeue();
        push(a);
    }
    while(top!=NULL){
        b=pop();
        enqueue(b);
    }
    display();
}
int main(){
    header=(Node*)malloc(sizeof(Node));
    header->link=NULL;
    header1=(Node*)malloc(sizeof(Node));
    header1->link=NULL;
    enqueue(7);
    enqueue(8);
    enqueue(9);
    reverse();
    return 0;
}
