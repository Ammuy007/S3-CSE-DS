#include <stdio.h>
#define N 30
#include <string.h>
char s[N];
int top=-1;
void push(char a){
    if(top==N-1){
        printf("Stack full\n");
    }
    else{
        s[++top]=a;
    }
}
char pop(){
    char item;
    if(top==-1){
        printf("Stack empty\n");
        return '\0';
    }
    else{
        item=s[top--];
        //printf("%c",item);
        return item;
    }
}

void main(){
    char str[N],rev[N];
    int i,j,k,flag=1;
    printf("Enter the string\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    i=0;
    while(top>=0){
    if(pop()!=str[i]){
        flag=0;
        break;
    }
    i++;
    }
    if(flag==0){
        printf("Not palindrome");
    }
    if(flag==1){
        printf("Palindrome");
    }
}
