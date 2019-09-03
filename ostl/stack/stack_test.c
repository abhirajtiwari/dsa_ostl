#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void main() {
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    STACK st;
    st.top = n;
    st.arr = (int *)malloc(n*sizeof(int));
    printf("Enter an array of %d elements: ", n);
    for(int i = 0; i<n; ++i) {
	scanf("%d", (st.arr+i));
    }

    stack_push(&st, 222); 
    for(int i = 0; i<st.top; ++i) {
	printf("%d ", *(st.arr+i));
    }

    printf("\n");
    
    printf("%d\n", stack_pop(&st));
    for(int i = 0; i<st.top; ++i) {
	printf("%d ", *(st.arr+i));
    }
    printf("\n");
}
