#include <stdio.h>
#include <stdlib.h>
#include "doublell.h"

int main()
{
	nodeptr a = initLL(0);
	for (int i = 1; i < 7; ++i)
	{
		insertLast(a, i);
	}
	insertFirst(&a, 7);
	printLL(a);
	printf("\n%d\n", deleteLast(a));
	printLL(a);
	printf("\n%d\n", deleteFirst(&a));
	printLL(a);
	return 0;
}
