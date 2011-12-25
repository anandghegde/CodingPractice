#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct data node link;
};

struct node* push(struct node *p, int value)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
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

struct node *pop(struct node *p)
{
	int tempInt;
	
