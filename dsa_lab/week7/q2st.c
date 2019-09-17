#include<stdio.h>
typedef struct{
	int arr[100];
	int top;
}stack;
void push(stack *s, int ele){
	s->arr[++s->top]=ele;
}
int popst(stack *s){
	return s->arr[s->top--];
}
int popq(stack *s1,stack *s2){
	if(s2->top!=-1){
		return s2->arr[s2->top--];
	}
	else if(s1->top!=-1){
		while(s1->top!=-1){
			push(s2,popst(s1));
		}
		return s2->arr[s2->top--];
	}
	else
		printf("Queue is empty");
		return -1;
}
void disp(stack *s1,stack *s2){
	int i;
	for(i=s1->top;i>=0;i--){
		printf("%d\t",s1->arr[i]);
	}
	for(i=0;i<=s2->top;i++){
		printf("%d\t",s2->arr[i]);
	}
}
int main(){
	stack s1, s2;
	s1.top=-1;
	s2.top=-1;
	while(1){
		printf("Type 1 to push, 2 to pop, 3 to display, 0 to exit");
		int inp, num;
		scanf("%d",&inp);
		if(inp==1){
			printf("Enter element to push");
			scanf("%d",&num);
			push(&s1, num);
		}
		if(inp==2){
			popq(&s1,&s2);
		}
		if(inp==3){
			disp(&s1,&s2);
		}
		if(inp==0){
			return 0;
		}	
	}
}