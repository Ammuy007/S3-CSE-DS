#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* LChild;
    struct Node* RChild;

}Node;
Node* Root=NULL;
void inorder(Node *ptr){
    if(ptr!=NULL){
    inorder(ptr->LChild);
    printf("%d ",ptr->data);
    inorder(ptr->RChild);
    }
}
Node* getnode(){
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    else{
        newnode->LChild=NULL;
        newnode->RChild=NULL;
        return newnode;
    }
}
void insert(Node* ptr,int item){
    int flag=0;
    Node* ptr1=NULL;
    while(ptr!=NULL && flag==0){
        if(item<ptr->data){
            ptr1=ptr;
            ptr=ptr->LChild;
        }
        else if(item>ptr->data){
                 ptr1=ptr;
            ptr=ptr->RChild;
        }
        else if(item==ptr->data){
            flag=1;
            printf("Already exists\n");
            break;
        }
    }
    if(ptr1!=NULL){
        Node *newnode=getnode();
        newnode->data=item;
        if(item<ptr1->data){
            ptr1->LChild=newnode;
        }
        else if(item>ptr1->data){
            ptr1->RChild=newnode;
        }
    }
    
}
int leafnode(Node* ptr) {
    if (ptr == NULL)
        return 0;
    else if (ptr->LChild == NULL && ptr->RChild == NULL)
        return 1;
    else
        return leafnode(ptr->LChild) + leafnode(ptr->RChild);
}

void search(Node* ptr,int key){
    int flag=0;
    while(ptr!=NULL && flag==0){
        if(key<ptr->data){
            ptr=ptr->LChild;
        }
        else if(key>ptr->data){
            ptr=ptr->RChild;
        }
        else if(key==ptr->data){
            flag=1;
            printf("%d found\n",key);
        }
    }
    if(flag==0){
        printf("%d not found",key);
    }
}
Node* successor(Node* ptr) {
    ptr = ptr->RChild;
    if(ptr!=NULL){
    while (ptr->LChild != NULL)
        ptr = ptr->LChild;
    }
    return ptr;
}

// Function to delete a node from the binary tree
void delete(Node* ptr,int key) {
    Node* parent = NULL;

    // Search for the key in the tree
    while (ptr != NULL && ptr->data != key) {
        parent = ptr;
        if (key < ptr->data)
            ptr = ptr->LChild;
        else
            ptr = ptr->RChild;
    }

    // If key not found
    if (ptr == NULL) {
        printf("Key not found\n");
        return;
    }

    // If node has no child
    if (ptr->LChild == NULL && ptr->RChild == NULL) {
        
        if (parent->LChild == ptr)
            parent->LChild = NULL;
        else if(parent->RChild == ptr)
            parent->RChild = NULL;
        free(ptr);
    }
    
    else if (ptr->LChild != NULL && ptr->RChild != NULL) {
        Node* succ = successor(ptr);
        int succData = succ->data;
        delete(Root,succ->data);
        ptr->data = succData;
    }
    
    else {
        if(parent->LChild==ptr){
                if(ptr->LChild==NULL){
                    parent->LChild=ptr->RChild;
                }
                else{
                    parent->LChild=ptr->LChild;
                }
        }
        else if(parent->RChild==ptr){
            if(ptr->LChild==NULL){
                parent->RChild=ptr->RChild;
            }
            else {
                    parent->RChild=ptr->LChild;
            }
        }
    }
}
int main(){
    int num;char choice;
    int key,c=0;
    int deletekey;
    do{
        printf("Enter your choice 1-Insert  2-search 3-delete 4-leafnode count\n ");
        scanf("%d",&num);
        switch(num){
            case 1:if(Root==NULL){
                    int rootdata;
                    Root=getnode();
                    printf("Enter the data of root node\n");
                    scanf("%d",&rootdata);
                    Root->data=rootdata;
                    break;
            }
            else{
                int item;
                printf("Enter the data to insert\n");
                scanf("%d",&item);
                insert(Root,item);
                inorder(Root);
                break;
            }
        case 2: 
            printf("Enter the key\n");
            scanf("%d",&key);
            search(Root,key);
            break;
        case 3:printf("Enter the data of node to delete");
            scanf("%d",&deletekey);
            delete(Root,deletekey);
            inorder(Root);
            break;
        case 4: c=leafnode(Root);
            printf("Number of leafnodes is %d\n",c);
                break;
        default:printf("Invalid choice");
        }
        printf("Do you wish to continue?\n");
        scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
}
