#include<stdio.h>
#define MAX_SIZE 100
void push( int i, int ele, int top[], int bound[],int arr[]){
	if(top[i]==bound[i+1]){
		printf("Stack is full");
	}
	else{
		arr[++top[i]]=ele;
	}
}
int pop(int i, int top[], int bound[], int arr[]){
	if(top[i]==bound[i]){
		printf("Empty stack");
	}
	else{
		return arr[top[i]--];
	}
}
void display(int i, int arr[], int top[], int bound[]){
	for(int j=bound[i]+1;j<=top[i];j++){
		printf("%d\t",arr[j]);
	}
}
int main(){
	int arr[MAX_SIZE];
	int top[2]={-1,49};
	int bound[3]={-1,49, 100};
	while(1){
		printf("Enter which stack to perform operation on: 1 or 2");
		int i;
		scanf("%d",&i);
		printf("Type 1 to push, 2 to pop, 3 to display, 0 to exit");
		int inp, ele;
		scanf("%d",&inp);
		if(inp==1){
			printf("Enter element");
			scanf("%d",&ele);
			push(i-1, ele, top, bound, arr);
		}
		if(inp==2){
			pop(i-1, top, bound, arr);
		}
		if(inp==3){
			display(i-1, arr, top, bound);
		}
		if(inp==0){
			return 0;
		}
	}

}