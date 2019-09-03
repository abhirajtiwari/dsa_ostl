#include <stdio.h>

int first_cap(char a[]) {
    int static i = 0;
    if (a[i] <= 'Z' && a[i] >= 'A') return i;
    else if (a[i] == '\0') return -1;
    else {
	++i;
	first_cap(a);
    }
}

int main() {
    printf("Enter a string: ");
    char input[50];
    gets(input);
    printf("First capital letter found at %d index\n", first_cap(input));
}
