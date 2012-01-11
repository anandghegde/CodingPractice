/*Queues using linked list */

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node{
	int data;
	struct node *link;
};

void insert(struct node **front, struct node **rear, int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nCouldnt allocate memory\n");
		exit(0);
	}

	temp->data=value;
	temp->link=NULL;
	if(*rear == NULL)
	{
		*rear=temp;
		*front = *rear;
	}
	else{
		(*rear)->link=temp;
		(*rear)=temp;
	}
}

void delete(struct node **front, struct node **rear, int *value)
{
	if((*front==*rear) && (*rear==NULL))
	{
		printf("Queue is empty\n");
		exit(0);
	}

	else{	*value=(*front)->data;
		struct node *temp=*front;
		(*front)=(*front)->link;
		if(*rear = temp)
		{
			*rear=NULL;
		}
		free(temp);
	}
}
int main(int argc, const char *argv[])
{
	struct node *front, *rear;front=rear=NULL;
	int n, choice,value;
	do{
	printf("\n1.Insert Element\n2.Delete Element\n3.Exit\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: printf("\nEnter the element to be inserted\n");
			scanf("%d", &value);
			insert(&front, &rear, value);
			break;
		case 2: delete(&front,&rear, &value);
			printf("Element deleted is %d", value);
			break;
		case 3:exit(0);
	}


}while(n!=3);
	return 0;
}
	
