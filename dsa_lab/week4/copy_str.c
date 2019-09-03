#include <stdio.h>

void copy(char a[], char b[]) {
    int static i = 0;
    if (b[i] == '\0') return;
    else a[i] = b[i];
    i++;
    copy(a, b);
}
   

int main() {
    printf("Enter a string: ");
    char input[20];
    scanf("%s", input);
    char input_copy[20];
    copy(input_copy, input);
    printf("%s\n", input_copy);
}

