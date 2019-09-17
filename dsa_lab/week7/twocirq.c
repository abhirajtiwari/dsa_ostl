#include<stdio.h>
#include<string.h>
#define max 6

void insertcq(int q[100],int *f1,int *r1,int *f2, int*r2,int item,int i)
{
	if(i==1)
	{
		if(*f1==max/2-1||(*f1==0&&*r1==max/2-1))
			{
				printf("CQueue_1 full\n");
				return;
			}
		*r1=(*r1+1)%(max/2);
		q[*r1]=item;
	}
	else if(i==2)
	{
		if(*f2==max-1||(*f2==(max/2)&&*r2==max-1))
		{
			printf("CQueue_2 full\n");
			return;
		}
		*r2=(*r2+1)%(max);
		q[*r2]=item;
	}
	
}
void deletecq(int q[100],int *f1,int *r1,int *f2, int*r2,int i)
{
	if(i==1)
	{
		if((*f1==max/2)||(*f1==0 && *r1==max/2))
			{
				printf("CQueue_1 empty\n");
			}
		else
			{
				printf("Deleted item: %d\n",q[*f1]);
				*f1=(*f1+1)%(max/2);
			}
	}
	else if(i==2)
	{
		if((*f2==max)||(*f2==max/2 && *r2==max))
			{
				printf("CQueue empty_2\n");
			}
		else
			{
				printf("Deleted item: %d\n",q[*f2]);
				*f2=(*f2+1)%(max);
			}
	}
}
void display(int q[100],int *f1,int *r1,int *f2, int*r2,int i)
{
	if(i==1)
	{
		if((*f1==max/2)||(*f1==0 && *r1==max/2))
			{
				printf("CQueue_1 empty\n");
				return;
			}

		int front;
		for(int i=0,front=*f1;front<=*r1;i++)
		{
			printf("%d   ",q[front]);
			front++;
		}
		printf("\n");
	}
	else if(i==2)
	{
		if((*f2==max)||(*f2==max/2 && *r2==max))
			{
				printf("CQueue empty_2\n");
				return;
			}
		int front;
		for(int i=0,front=*f2;front<=*r2;i++)
		{
			printf("%d   ",q[front]);
			front++;
		}
		printf("\n");
	}
}
void main()
{
	int q[100],item;
	int n,k,t,f1=0,r1=-1,f2=max/2,r2=max/2-1;
	while(1)
	{	printf("Enter\n1 to exit\n2 to choose queue\n");
		scanf("%d",&n);
		if(n==2)
			{
				printf("Enter the no. of queue on which to operate(1or2)\n");
				scanf("%d",&t);
			
				
				for(;;)
				{
					printf("Enter\n1 to push\n2 to pop\n3 to display\n4 to exit\n");
					scanf("%d",&k);
					if(k==1)
					{
						printf("Enter item\n");
						scanf("%d",&item);
						insertcq(q,&f1,&r1,&f2,&r2,item,t);
					}
					else if(k==2)
					{
						deletecq(q,&f1,&r1,&f2,&r2,t);
					}
					else if (k==3)
					{
						display(q,&f1,&r1,&f2,&r2,t);
					}
					else
					{
						break;
					}

				}

			}
		else
		{
			break;
		}
	}
}