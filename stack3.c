#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        exit(EXIT_FAILURE);
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        exit(EXIT_FAILURE);
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (s->top == -1) {
        exit(EXIT_FAILURE);
    }
    return s->arr[s->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        case '^': {
            double result = pow(operand1, operand2);
            if (result > INT_MAX || result < INT_MIN) {
                exit(EXIT_FAILURE);
            }
            return (int)result;
        }
        default:
            exit(EXIT_FAILURE);
    }
}

int postfix(const char *expression) {
    Stack operands;
    operands.top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isdigit(c)) {
            push(&operands, c - '0');
        } else if (isOperator(c)) {
            if (operands.top < 1) {
                exit(EXIT_FAILURE);
            }
            int operand2 = pop(&operands);
            int operand1 = pop(&operands);
            int result = performOperation(operand1, operand2, c);
            push(&operands, result);
        } else if (isspace(c)) {
            continue;
        } else {
            exit(EXIT_FAILURE);
        }
    }

    if (operands.top != 0) {
        exit(EXIT_FAILURE);
    }

    return peek(&operands);
}

int main() {
    char pfix[MAX_SIZE];

    printf("Enter the postfix expression: ");
    fgets(pfix, MAX_SIZE, stdin);
    pfix[strcspn(pfix, "\n")] = 0;

    int result = postfix(pfix);
    printf("Result: %d\n", result);

    return 0;
}