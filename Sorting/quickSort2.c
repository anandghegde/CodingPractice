#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int choose_pivot(int x, int y)
{
	return ((x+y)/2);
}

void printArray(int array[], int numberOfElements)
{
	int k;
	for(k=0;k<numberOfElements;k++)
		printf("%d\t",array[k]);
	printf("\n");
}


void quickSort(int list[], int m, int n)
{
	int key, i,j,k;
	if(m<n)
	{
		key=list[m];
		i=m+1;
		j=n;
		while(i<=j)
		{
			while((i<=n) && (list[i]<=key))
				i++;
			while((j>=m) && (list[j]>key))
				j--;
			if(i<j)
				swap(&list[i], &list[j]);
				printArray(list, n);
		}
	
		swap(&list[m], &list[j]);
		printArray(list, n);
		quickSort(list, m, j-1);
		quickSort(list, j+1, n);
	}
}

void main()
{
	int array[100], i,j,k,n;
	printf("Enter the nummber of elements in the array:\n");	
	scanf("%d", &n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &array[i]);
	}
	printf("Array before sorting:\n");
	printArray(array,n);
	printf("Array after sorting::\n");
	quickSort(array, 0, n-1);
	printArray(array,n);
}	
