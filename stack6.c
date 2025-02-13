#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
	int items [MAX];
	int top;

} stack;

void initstack(stack *s) {
	s->top = -1;
}

int isempty(stack *s) {
	return s->top == -1;
}

void push(stack *s, int value) {
	if (s->top < MAX - 1) {
		s->items[ ++s->top] = value;
	}
	else {
		printf("stack is full\n");
	}
}

void removemin(stack *s) {
	if(isempty(s)) {
		printf("Stack is empty\n");
		return;

	}

	int min=INT_MAX;
	int minIndex = -1;

	for(int i = 0 ; i<= s->top; i++) {
		if(s->items[i]<min) {
			min = s->items[i];
			minIndex = i;
		}
	}



	for(int i=0; i<= s->top ; i++) {
		if( s->items[i] < min) {
			min = s->items[i];
			minIndex = i;
		}
	}


	for(int i= minIndex; i< s->top ; i++) {
		s->items[i] = s->items[i + 1];

	}

	s->top--;
	printf("removed minimum element : %d\n", min);


}


void display(stack *s) {
	if(isempty(s)) {
		printf("stack is empty\n");

	}
	else {
		printf("stack elements are: ");
		for(int i =0; i <= s->top; i++) {
			printf("%d ",s->items[i]);

		}
		printf("\n");
	}
}


int main() {

	stack s;
	initstack(&s);
	int n, value;


	printf("number of elements ");
	scanf("%d",&n);


	printf("enter %d numbers :\n", n);
	for(int i=0; i<n; i++) {
		scanf("%d", &value);
		push(&s, value);
	}


	printf("initial stack\n");
	display(&s);

	removemin(&s);

	printf("stack after removing minimum:\n");
	display(&s);


	return 0;
}