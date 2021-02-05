//b171152
//insertion sorting

#include<stdio.h>
void main()
{
	int a[50],i,j,temp,n;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		j=i;
		while(j>0 && a[j-1]>a[j])
		{
			temp=a[i];
			a[i]=a[j-1];
			a[j-1]=temp;
			j--;
		}
	}
	printf("Sorted elements:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
//b171152
