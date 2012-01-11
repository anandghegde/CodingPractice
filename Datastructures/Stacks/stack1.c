/*Stack using array*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void push(int stack[], int *top, int value)
{
	if(*top<MAX)
	{
		*top=*top+1;
		stack[*top]=value;
	}
	
	else{
		printf("Stack is full\n");
		exit(0);
		}
}

void pop(int stack[], int *top, int *value)
{
	if(*top>=0)
	{
		*value=stack[*top];
		*top=*top-1;
	}
	else{
		printf("Stack is empty\n");
		exit(0);
		}
}

void main()
{
	int stack[MAX];
	int top=-1;
	int n, value;
	do{
		do{
			printf("Enter the value to be pushed:\n");
			scanf("%d", &value);
			push(stack, &top, value);
			printf("Enter 1 to continue:\n");
			scanf("%d", &n);
			}while(n==1);
		printf("Enter 1 to pop an element:\n");
		scanf("%d", &n);
		while(n==1)
		{
			pop(stack, &top, &value);
			printf("The popped value is %d\n",value);
			printf("Enter 1 to pop an element:\n");
			scanf("%d", &n);
		}
		printf("Enter 1 to continue:\n");
		scanf("%d", &n);
	}while(n==1);
} 
