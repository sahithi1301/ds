#include<stdio.h>
#include<stdlib.h>
void mergesort(int a[20],int st,int mid,int end)
{
	int b[20],i=0,j=mid+1,k=0;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	if(j<=end)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		a[st+i]=b[i];
	}
	

}
int merge(int a[20],int st,int end)
{
	int mid,k;
	if(st<end)
	{
		mid=(st+end)/2;
		merge(a,st,mid);
		merge(a,mid+1,end);
		mergesort(a,st,mid,end);	
	}
		printf("enter sorterd array\n");
		for(k=0;k<=end;k++)
	{
		printf("%d",a[k]);
	}

}
int main()
{
	int a[20],b[20],st=0,end,n,i,j,k;
	printf("enter the size of array:");
	scanf("%d",&n);
	end=n-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge(a,0,n);
	
	return 0;	
}
