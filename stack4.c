#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == 99) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        exit(1);
    }
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void sortStack(Stack *input) {
    Stack temp;
    temp.top = -1;

    while (!isEmpty(input)) {
        int current = pop(input);

        while (!isEmpty(&temp) && peek(&temp) > current) {
            push(input, pop(&temp));
        }
        push(&temp, current);
    }

    while (!isEmpty(&temp)) {
        push(input, pop(&temp));
    }
}

int main() {
    Stack s;
    s.top = -1;

    push(&s, 5);
    push(&s, 2);
    push(&s, 8);
    push(&s, 1);
    push(&s, 4);

    printf("Original stack: ");
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    push(&s, 5);
    push(&s, 2);
    push(&s, 8);
    push(&s, 1);
    push(&s, 4);

    sortStack(&s);

    printf("Sorted stack: ");
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    return 0;
}
