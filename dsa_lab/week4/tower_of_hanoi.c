#include <stdio.h>

int moves = 0;
void tower(int n, char source, char temp, char destination)
{
    if (n==1)
    {
	printf("move disk 1 from %c to %c\n", source, destination);
	moves++;
	return;
    }
    tower(n-1, source, destination, temp);
    printf("move disk %d from %c to %c\n", n, source, destination);
    moves++;
    tower(n-1, temp, source, destination);
}

int main() {
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    printf("Number of moves = %d\n", moves);
}
