#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(char value) {
    if (isFull()) {
        return;
    }
    stack[++top] = value;
    
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top];
}

int priority(char c) {
    if (c == '^') {
        return 3;
    }
    if (c == '/' || c == '*') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0; 
}

int main() {
    char s[20], pfix[20] = "";
    printf("Enter the expression here => ");
    scanf("%s", s);

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) { 
            strncat(pfix, &s[i], 1); 
        }
        else if (s[i] == '(') {
            push(s[i]);
        } 
        else if (s[i] == ')') {
            while (top != -1 && stack[top] != '(') { 
                char p = pop();
                strncat(pfix, &p, 1);
            }
            if (top != -1) { 
                pop(); 
            }
        } 
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            while (top != -1 && priority(stack[top]) >= priority(s[i])) {
                char p = pop();
                strncat(pfix, &p, 1);
            }
            push(s[i]);
        }
    }

    while (top != -1) {
        char p = pop();
        strncat(pfix, &p, 1);
    }

    printf("Postfix expression: %s\n", pfix);

    return 0;
}