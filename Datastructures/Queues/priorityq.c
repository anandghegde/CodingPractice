/*Priority queue using linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int priority;
	struct node *link;
};

void insert(struct node **front, struct node **rear, int value, int priority)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Failed to allocate memory\n");
		exit(0);
	}
	temp->data=value;
	temp->priority=priority;
	temp->link=NULL;
	if(*rear==NULL)
	{
		*rear=temp;
		*front=*rear;
	}
else{
	if((*front)->priority<priority)
	{
		temp->link=(*front);
		*front=temp;
	}
	if((*rear)->priority>priority)
	{
		(*rear)->link=temp;
		(*rear)=temp;
	}
	else{
		struct node *temp1;
		temp1=(*front);
		while((temp1->link)->priority>=priority)
			temp1=temp1->link;
		temp->link=temp1->link;
		temp1->link=temp;
		}
}
}

void delete(struct node **front, struct node **rear, int *value, int *priority)
{
	if((*front==*rear) && (*rear==NULL))
	{
		printf("Queue is empty\n");
		exit(0);
	}

	else{	struct node *temp;
		*value=(*front)->data;	
		*priority = (*front)->priority;
		temp=*front;
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
	struct node *front=NULL;struct node *rear=NULL;
	int n, choice,value;int priority;
	do{
	printf("\n1.Insert Element\n2.Delete Element\n3.Exit\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: printf("\nEnter the element to be inserted\n");
			scanf("%d", &value);
			printf("Enter the priority of the value\n");
			scanf("%d", &priority);
			insert(&front, &rear, value, priority);
			break;
		case 2: delete(&front,&rear, &value, &priority);
			printf("Element deleted is %d and its priority is %d", value, priority);
			break;
		case 3:exit(0);
	}
}while(n!=3);
return 0;
}
