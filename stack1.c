#include<stdio.h>
#include<string.h>
#define max 100
typedef struct{
    char arr[max];
    int top;
}Stack;

void ini(Stack *s){
    s->top=-1;
}

void push(Stack *s,char a){
    s->arr[++s->top]=a;
    
}

void pop(Stack *s){
    char pop=s->arr[s->top];
    s->top--;
    printf("%c",pop);
}
int main(){
    Stack stack;
    ini(&stack);
    
    char a[10];
    printf("enter a string");
    gets(a);
    
    for (int i=0;i<strlen(a);i++){
        push(&stack,a[i]);
    }
    for(int i=0;i<strlen(a);i++){
        pop(&stack);
    }
}