#include <stdio.h>
#include <string.h>

void print_back(char a[]) {
    int n = strlen(a)-1;
    int static i = 0;
    if (n-i < 0) return;
    printf("%c", a[n-i]);
    i++;
    print_back(a);
}

int main() {
    printf ("Enter a string: ");
    char input[50];
    gets(input);
    print_back(input);
}
