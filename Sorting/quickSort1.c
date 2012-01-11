#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 30


void printArray(int array[], int numberOfElements)
{
	int k;
	for(k=0;k<numberOfElements;k++)
		printf("%d\t", array[k]);
	printf("\n");
}
void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
int nOfArray = right;
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
	printArray(numbers, nOfArray);
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
	printArray(numbers, nOfArray);
      right--;
    }
  }
  numbers[left] = pivot;
printArray(numbers, nOfArray);
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}

void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}

void main()
{	int a[MAX_ELEMENT];int n,i,j,k;
	printf("Enter the number of elements to be sorted:\n");
	scanf("%d", &n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Array before sorting:\n");
	printArray(a,n);
        quickSort(a, n);
	//printf("Array after sorting\n");
	printArray(a,n);
}	
