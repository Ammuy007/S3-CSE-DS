#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top = -1, size = 20;
char stack[20];
char expr[50], postfix[50];

int isp(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '^':
        return 5;
        break;
    case '(':
        return 0;
        break;
    }
}

int icp(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '^':
        return 6;
        break;
    case '(':
        return 7;
        break;
    }
}

void push(char item) {
    if (top == size - 1) {
        printf("STACK OVERFLOW\n");
    } else {
        top += 1;
        stack[top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return '\0';
    } else {
        char item = stack[top];
        top = top - 1;
        return item;
    }
}

void postfixexp(char exp[], char postfix[]) {
    int index;
    int l = strlen(exp);
    exp[l] = ')';
    exp[l + 1] = '\0';
    push('(');
    int i = 0;
    index = 0;
    while (exp[i] != '\0') {
        char item = exp[i];
        char s = pop();
        if (isdigit(item)) {
            postfix[index++] = item;
            push(s);
        } else if (item == ')') {
            while (s != '(') {
                postfix[index++] = s;
                s = pop();
            }
        } else if (icp(item) <= isp(s)) {
            while (icp(item) <= isp(s)) {
                postfix[index++] = s;
                s = pop();
            }
            push(s);
            push(item);
        } else {
            push(s);
            push(item);
        }
        i++;
    }
    postfix[index] = '\0';
}

int evaluate(char postfix[]) {
    int operand, result;
    int i = 0;
    while (postfix[i] != '\0') {
        char term = postfix[i];
        if (isdigit(term)) {
            operand = term - '0';
            push(operand);
        } else {
            int toppest = pop();
            int secondtop = pop();
            switch (term) {
            case '+':
                result = secondtop + toppest;
                break;
            case '-':
                result = secondtop - toppest;
                break;
            case '*':
                result = secondtop * toppest;
                break;
            case '/':
                result = secondtop / toppest;
                break;
            case '^':
                result = pow(secondtop, toppest);
                break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    printf("Enter the infix expression: ");
    scanf(" %s", expr);
    postfixexp(expr, postfix);
    printf("The postfix expression is : ");
    printf("%s\n", postfix);
    printf("Result: %d\n", evaluate(postfix));
    return 0;
}
