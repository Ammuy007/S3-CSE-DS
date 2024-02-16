#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;
Node* header;
void insert_beg(int x){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Memory allocation Failed\n");
    }
    else{
        newnode->data=x;
        newnode->link=header->link;
        header->link=newnode;
    }
}
void insert_end(int x){
    Node* ptr=header;
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Memory allocation Failed\n");
    }
    else{
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            ptr->link=newnode;
            newnode->data=x;
            newnode->link=NULL;
    }
}
void insert_random(int x){
    Node* ptr=header;
    int key;
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Memory allocation Failed\n");
    }
    else{
        printf("Enter key\n");
        scanf("%d",&key);
        while(ptr!=NULL && ptr->data!=key){
            ptr=ptr->link;
        }
        if(ptr->data==key){
            newnode->link=ptr->link;
            ptr->link=newnode;
            newnode->data=x;
        }
        else{
            printf("Key not found\n");
            
        }
    }
}
void display(){
    Node* ptr=header->link;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
}
int delete_end(){
Node* ptr=header->link;
int item;
Node* temp;
if(ptr==NULL){
    printf("List empty\n");
}
else{
    while(ptr->link!=NULL){
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    item=ptr->data;
    free(ptr);
    return item;
}
}
int delete_beg(){
    Node* ptr=header->link;
    int item;
    if(ptr==NULL){
        printf("List empty\n");
    }
    else{
        header->link=ptr->link;
        item=ptr->data;
        free(ptr);
        return item;
    }
}
void delete_random() {
    Node* ptr = header->link;
    Node* temp = header;
    int key, item;
    if (ptr == NULL) {
        printf("List empty\n");
    }
    else {
        printf("Enter key: ");
        scanf("%d", &key);
        while (ptr != NULL && ptr->data != key) {
    temp = ptr;
    ptr = ptr->link;
}

        temp->link=ptr->link;
        item=ptr->data;
        free(ptr);
        //return item;
    }
}

int main(){
    int data,option,d;
    char choice;
    header=(Node*)malloc(sizeof(Node));
    header->link=NULL;
    do{
        printf("Enter your choice 1-insert at front 2-insert at end 3-insert at random 4-delete at beg 5-delete at end 6-delete at random 7-display\n");
        scanf(" %d",&option);
        switch(option){
            case 1:printf("Enter data\n");
            scanf("%d",&data);
            insert_beg(data);
            break;
            case 2: printf("Enter data\n");
                scanf("%d",&data);
            insert_end(data);
            break;
            case 3:printf("Enter data\n");
                scanf("%d",&data);
            insert_random(data);
            break;
            case 4:d=delete_beg();
            printf("Deleted %d\n",d);
            break;
            case 5:d=delete_end();
            printf("Deleted %d\n",d);
            break;
            case 6:delete_random();
            break;
            case 7:display();
            break;
            default:printf("Enter a valid choice\n");
            break;
        }
        printf("Do you wish to continue?\n");
        scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
    return 0;
}
