//b171152
//bubble sorting 

#include <stdio.h>
void main()
{
	int i,j,a[30],l,k;
	printf("enter length of array: ");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-1;j++)
		{
			int temp;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
 			}
		}
		//printing pass
		printf("\n pass");
		for(k=0;k<l;k++)
		{
			printf("%d\t",a[k]);
		}
	}
}
//b171152				
