#include <stdio.h>
#include <stdlib.h>

int** modifier (int** a, int n) {
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total+=(**(a+i));
	}

	*(a+n-1) = (int *)realloc(*(a+n-1), sizeof(int)*total);
	for (int i = 0; i < n-1; ++i)
	{
		int sub_n = **(a+i);
		for (int j = 0; j < sub_n; ++j)
		{
			*(*(a+n-1) + **(a+n-1) + 1) = *(*(a+i)+j);
			(**(a+n-1))++;
		}
		free(*(a+i));
	}
	return a;
}

int main() {
	int rowNum, colNum, i, j;
	int **table;
	printf("\nEnter the number of rows\n");
	scanf("%d", &rowNum);
	table = (int**)calloc(rowNum+1, sizeof(int *));
	for (int i = 0; i <rowNum; ++i) {
		printf("Enter the size of %d row: ", i);
		scanf("%d", &colNum);
		table[i] = (int *) calloc(colNum+1, sizeof(int));
		printf("Enter the row elements: ");
		for (int j = 1; j <= colNum; ++j) {
			scanf("%d", &table[i][j]);
		}
		table[i][0] = colNum;
		printf("size of row num %d = %d\n", i+1, table[i][0]);
	}

	for(int i = 0; i < rowNum; ++i) {
		printf("Displaying %d row elements\n", i+1);
		for(int j = 0; j <= table[i][0]; ++j) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}

	table = modifier(table, rowNum);

	//Print again
	for(int i = 0; i < rowNum; ++i) {
		printf("Displaying %d row elements\n", i+1);
		for(int j = 0; j <= table[i][0]; ++j) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i <rowNum; ++i) {
		free(table[i]);
	}
	free(table);
	return 0;
}