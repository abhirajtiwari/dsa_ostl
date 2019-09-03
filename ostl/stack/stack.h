typedef struct {
    int top;
    int *arr;
} STACK;

void stack_push(STACK*, int);

int stack_pop(STACK*);
