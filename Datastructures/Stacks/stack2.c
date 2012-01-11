/*Stack using linked lists*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node{
	int data;
	struct node *link;
};

struct node *push(struct node *p, int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory couldnt be allocated\n");
		exit(0);
	}
	temp->data=value;
	temp->link=p;
	p=temp;
	return(p);
}

struct node *pop(struct node *p, int *value)
{
	struct node *temp;
	if(p==NULL)
	{
		printf("\nStack is empty:\n");
		exit(0);
	}
	*value=p->data;
	temp=p;
	p=p->link;
	free(temp);
	return(p);
}

void main()
{	
	struct node *top=NULL;
	int n, value;
	int choice;
do{
	printf("What do you want to do?\n");
	printf("1.Push an element\n");
	printf("2.Pop an element\n");
	printf("3.Exit\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: printf("Enter the value to be pushed\n");
			scanf("%d", &value);
			top=push(top, value);
			break;
		case 2: top=pop(top, &value);
			printf("The value popped is %d\n", value);
			break;
		case 3: exit(0);
	}
}while(n!=3);
}	
