#include <string.h>
#include <stdio.h>
#include "stack.h"

int isOperand(char a) {
	if (a >= '0' && a <= '9') return 1;
	else return 0;
}

int isOperator(char a) {
	switch (a) {
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}

char operate(char b, char a, char operator) {
	int a_val = a - '0';
	int b_val = b - '0';
	switch (operator) {
		case '+':
			return '0' + (a_val + b_val);
		case '-':
			return '0' + (a_val - b_val);
		case '*':
			return '0' + (a_val * b_val);
		case '/':
			return '0' + (a_val / b_val);
	}
}

int main() {
	printf("Enter a prefix expression: ");
	char c[100];
	STACK input;
	input.top=-1;
	scanf("%s", c);
	for (int i = 0; c[i] != '\0'; ++i) {
		if (c[i] == '(') c[i] = ')';
		else if (c[i] == ')') c[i] = '(';
	}
	for (int i = strlen(c)-1; i >= 0; --i) {
		char token = c[i];
		if (isOperand(token)) pushStack(&input, token);
		if(isOperator(token))
			pushStack(&input, operate(popStack(&input), popStack(&input), token));
	}
	printf("Evaluated answer is %d\n", peekStack(&input) - '0');
}