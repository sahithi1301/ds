#include <stdio.h>
#define size 100
void merge(int [],int,int,int);
void mergesort(int [],int,int);
void main()
{
	int a[100],i,n;
	printf("enter the number of elements: ");
	scanf("%d",&n);
	printf("enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("the sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void mergesort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}
void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[size],k;
	while((i<=mid)&&(j<=end))
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	{
		arr[k]=temp[k];
		//printf("%d\t",arr[k]);
	}
}


		
