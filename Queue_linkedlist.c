#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;
Node* header,*newnode,*front=NULL,*rear=NULL;
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
int main(){
    int s;
   header=(Node*)malloc(sizeof(Node));
    header->link=NULL;
    enqueue(1);
    enqueue(2);
    printf("\n");
    display();
    s=dequeue();
    printf("\ndeleted %d\n",s);
    display();
    enqueue(3);
    display();

}
