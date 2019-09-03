#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
	return n;
    }
    else {
	return fib(n-1) + fib(n-2);
    }
}

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
	printf("%d ", fib(i));
    }
    printf("\n");
}
