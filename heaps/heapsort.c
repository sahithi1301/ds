//b171152
//Implementation of heap sorting
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void heapify(int arr[],int n , int i)
{
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && (arr[l]>arr[large]))
	{
		large=l;
	}
	if(r<n && (arr[r]>arr[large]))
	{
		large=r;
	}
	if(large!=i)
	{
		swap(&arr[i],&arr[large]);
		heapify(arr,n, large);
	}
}
void heapSort(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	printf("\n");
}
int main()
{
	int n,i;
	int list[30];
	printf("Enter  no of elements\n");
	scanf("%d",&n);
	printf("Enter values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	heapSort(list,n);
	printf("Sorted array is:");
	print(list,n);
	return 0;
}
//b171152
