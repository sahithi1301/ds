#include<stdio.h>
#include<stdlib.h>
int swap(int a[20],int i,int j)
{
	int tmp;
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	return 0;
};
int quicksort(int a[20],int st,int end)
{
	int pivot,i,j;
	if(end-st>1)
	{
	pivot=a[st];
	i=st+1;
	j=end;
	while(i<j)
	{
		while(a[i]<pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		swap(a,i,j);
	}
	swap(a,st,j);
	quicksort(a,st,j-1);
	quicksort(a,j+1,end);
	}
	else
	{
		if(a[st]>a[end])
		{
			swap(a,st,end);
		}
	}
	return 0;
}
int main()
{
	int a[20],st=0,end,n,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("enter the elements of the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	end=n;
	quicksort(a,st,end);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
