#include <stdio.h>
#include <string.h>

int check_palin(char a[]) {
    int static j = 0;
    int i = 0;
    int n = strlen(a)-1;
    i = i + j;
    n = n - j;
    if (a[i] != a[n]) return 0;
    else if (i >= strlen(a)/2) return 1;
    else {
	j++;
	check_palin(a);
    }
}

int main() {
    printf("Enter string: ");
    char input[20];
    scanf("%s", input);
    int resp = check_palin(input);
    if (resp) printf("Is a palindrome.\n");
    else printf("Not a palindrome.\n");
}
    
    
