#include <stdio.h>
#include <string.h>

#define MAX 100



int isbalanced(const char *expr) {
	char stack[MAX];
	int top = -1;

	for (int i = 0 ; i< strlen(expr); i++) {
		if(expr[i]=='(') {
			stack[++top]=='(';

		}
		else if(expr[i]==')') {
			if(top == -1) return 0;
			top--;
		}
	}
	return top == -1;
}

int main() {

	char expr[MAX];
	printf("Enter a string of parentheses: ");
	scanf("%s", expr);

	if (isbalanced(expr)) {
		printf("the string is balanced:\n");

	}
	else {
		printf("the string is not balanced:\n");
	}

	return 0;
}