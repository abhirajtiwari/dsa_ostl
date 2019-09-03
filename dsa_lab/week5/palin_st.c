#include <stdio.h>
#include <string.h>
#include "stack.h"

int checkPalinStack(char a[]) {
	int len = strlen(a);
	int i;
	STACK in;
	in.top = 0;
	for (i = 0; i < len/2; ++i) pushStack(&in, a[i]);
	for (i += (len%2); i < len; ++i) {
		if (popStack(&in) != a[i]) return 0;
	}
	return 1;
}

int main() {
	printf("Enter a string: ");
	char input[100];
	scanf("%s", input);
	if (checkPalinStack(input)) printf("Palindrome!!\n");
	else printf("Not a Palindrome\n");
}