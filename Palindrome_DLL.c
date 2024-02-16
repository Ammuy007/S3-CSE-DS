#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node* rlink;
    struct node* llink;
}Node;
Node* header,*newnode;
void display(){
    Node* ptr=header->rlink;
    if(ptr==NULL){
        printf("List empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("%c",ptr->data);
            ptr=ptr->rlink;
        }
    }
}
void insert(char x){
    Node* ptr=header;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
            printf("Failed\n");
    }
    else{
        if(header->rlink==NULL){
            header->rlink=newnode;
            newnode->rlink=NULL;
            newnode->llink=header;
            newnode->data=x;
        }
        else{
            while(ptr->rlink!=NULL){
                ptr=ptr->rlink;
            }
            ptr->rlink=newnode;
            newnode->llink=ptr;
            newnode->rlink=NULL;
            newnode->data=x;
        }
    }
}
int palcheck(){
    Node* left=header->rlink;
    Node* right=header->rlink;
    while(right->rlink!=NULL){
        right=right->rlink;
    }
    while(left!=NULL && right!=NULL && left!=right){
        if(left->data!=right->data){
            return -1;
        }
        else{
            left=left->rlink;
            right=right->llink;
        }
    }
    return 1;
}
int main(){
    header=(Node*)malloc(sizeof(Node));
    header->rlink=NULL;
    header->llink=NULL;
    int s;
    char str[10]="abc";
    int i;
    for(i=0;str[i]!='\0';i++){
        insert(str[i]);
    }
    display();
    s=palcheck();
    if(s==1){
        printf("Palindrome\n");

    }
    else{
        printf("Not palindrome\n");
    }
    return 0;
}
