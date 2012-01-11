/*Queues using arrays*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void insert(int queue[], int *rear, int value)
{
	if(*rear>=MAX)
	{
		printf("No Space in queue\n");
		exit(0);
	}
	else{
		*rear=*rear+1;
		queue[*rear]=value;
	}
}

void delete(int queue[], int *front, int rear, int *value)
{
	if(*front==rear)
	{
		printf("You cannot delete - empty");
		exit(0);
	}

	*front = *front+1;
	*value=queue[*front];
}

void main()
{
	int queue[MAX];
	int front, rear;
	front=rear=-1;int n;int choice;
	int value;
	do{
		printf("What do you want to do?\n 1.Insert\n2.Delete\n3.Exit\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1: printf("Enter the number to be inserted:\n");
				scanf("%d", &value);
				insert(queue, &rear, value);
				break;
			case 2: delete(queue, &front, rear, &value);
				printf("The value deleted is %d\n", value);
				break;
			case 3: exit(0);
		}
	}while(n!=3);
}	
