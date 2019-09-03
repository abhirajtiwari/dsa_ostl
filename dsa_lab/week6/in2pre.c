#include "stack.h"
#include <stdio.h>
#include <string.h>

int isp(char a) {
	switch (a) {
		case '/': 
		case '*': return 6;
		case '+':
		case '-': return 5;
		case '(': return 4;
		default : return -1;
	}
}

int osp(char a) {
	switch (a) {
		case '(': return 7;
		case '/': 
		case '*': return 6;
		case '+':
		case '-': return 5;
		default : return -20;
	}
}

/*char[] reverse(char *a) {
	char reversed_string[100];
	for (int i = 0; i <= strlen(a); ++i)
	{
		reversed_string[strlen(a)-i] = a[i]; 
	}
	return reversed_string;
}*/

int main() {
	char infix[100];
	STACK stack;
	stack.top = -1;

	printf("Enter an infix expression: ");
	scanf("%s", infix);

	// char infix_rev[100] = strrev(infix);

	for (int i = 0; i < strlen(infix); ++i)
	{
		printStack(&stack);
		if (osp(infix[i]) > isp(peekStack(&stack))) pushStack(&stack, infix[i]);
		else {
			printf("%c", infix[i]);
			while(osp(infix[i]) >= isp(peekStack(&stack))) {
				char popped = popStack(&stack);
				printf("%c", popped);
			}
			pushStack(&stack, infix[i]);
		}
	}
}