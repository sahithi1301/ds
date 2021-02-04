#include <stdio.h>
void main()
{
	int i,a[30],low,temp,l,j,k;
	printf("enter length of array: ");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		scanf("%d",&a[i]);
	}
 
   for(i=0;i<l;i++)
   {
   	low=a[i];
      for(j=i+1;j<l;j++)
	  {
         if(low>a[j]){
            temp=low;
            low=a[j];
            a[j]=temp;
         }
         
      }
   		a[i]=low;
		printf("\npass");
		for(k=0;k<l;k++)
			printf("\t%d",a[k]);
	}
	
}

			
		
