#include<stdio.h>
typedef struct{
	int arr[100];
	int beg, end;
}queue;
void push(queue *q, int ele){
	q->arr[++q->end]=ele;
}
int pop(queue *q){
	if(q->beg==q->end){
		printf("Queue is empty");
		return 0;
	}
	else
	return q->arr[++q->beg]; 
}
void display(queue *q){
	int i;
	for(i=q->beg+1;i<=q->end;i++){
		printf("%d\t",q->arr[i]);
	}
}
void search(queue *q, int ele){
	int i, poppedele,f=0;
	int end=q->end;
	for(i=q->beg+1;i<=end;i++){
		poppedele=pop(q);
		push(q, poppedele);
		if(poppedele==ele){
			printf("Element found at position %d",i);
			f=1;
		}
	}
	if(f==0)
	printf("Not found");
}
int main(){
	queue q;
	q.beg=-1;
	q.end=-1;
	int ele, inp, num;
	while(1){
		printf("Type 1 to push, 2 to pop, 3 to display, 0 to exit");
		scanf("%d",&inp);
		if(inp==1){
			printf("Enter element to push");
			scanf("%d",&num);
			push(&q, num);
		}
		if(inp==2){
			pop(&q);
		}
		if(inp==3){
			display(&q);
		}
		if(inp==0){
			break;
		}
	}
	printf("Enter element to search");
	scanf("%d",&ele);
	search(&q, ele);
	return 0;
}