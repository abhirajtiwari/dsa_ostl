#include<stdio.h>
#include<string.h>
#define MAX 5
typedef struct{
	char arr[100][100];
	int beg, end;
}QUEUE;
void insertcq(char a[], QUEUE *str){
	str->end++;
	str->end=str->end%MAX;
	if(str->end==str->beg){
		printf("Queue is full");
		if(str->end==0) str->end=MAX-1;
		else str->end=str->end-1;
	}
	else{
		for(int i=0;i<strlen(a);i++){
			str->arr[str->end][i]=a[i];
		}
	}
}
void deletecq(QUEUE *str){
	if(str->beg==str->end){
		printf("Queue is empty");
		return;
	}
	str->beg++;
	str->beg=str->beg%MAX;
	printf("%s",str->arr[str->beg]);
}
void displaycq(QUEUE *str){
	int i;
	if(str->beg<str->end)
	for(i=str->beg+1;i<=str->end;i++){
		printf("%s\t",str->arr[i]);
	}
	else if(str->end<str->beg){
		for(i=str->beg+1;i<MAX;i++){
			printf("%s\t", str->arr[i]);
		}
		for(i=0;i<=str->end;i++){
			printf("%s\t",str->arr[i]);
		}
	}
}
int main(){
	QUEUE str;
	str.beg=0; str.end=0;
	int inp;
	char a[100];
	while(1){
		printf("Type 1 to push, 2 to pop, 3 to display, 0 to exit");
		scanf("%d",&inp);
		if(inp==1){
			printf("Enter string to push");
			scanf("%s",a);
			insertcq(a, &str);
		}
		if(inp==2){
			deletecq(&str);
		}
		if(inp==3){
			displaycq(&str);
		}
		if(inp==0){
			return 0;
		}
	}
}