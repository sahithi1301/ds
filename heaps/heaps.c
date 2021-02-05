//b171152
//Implementation of heaps
#include <stdio.h>
#include <limits.h>

int heap[1000000],heapSize;
void Init()
{
	heapSize=0;
	heap[0]=INT_MAX;
}
void Insert(int ele)
{
	heapSize++;
	heap[heapSize]=ele;
	int now=heapSize;
	while(heap[now/2]>ele)
	{
		heap[now]=heap[now/2];
		now=now/2;
	}
	heap[now]=ele;
}
int deleteMin()
{
	int minEle,lastEle,child,now;
	minEle=heap[1];
	lastEle=heap[heapSize-1];
	for(now=1;now*2<=heapSize;now=child)
	{
		child=now*2;
		if(child!=heapSize && heap[child+1]<heap[child])
		{
			child++;
		}
		if(lastEle>heap[child])
		{
			heap[now]=heap[child];
		}
		else
		{
			break;
		}
	}
	heap[now]=lastEle;
	return minEle;
}
int main()
{
	int len;
	printf("\nEnter the number of elements: ");
	scanf("%d",&len);
	int i, ele;
	Init();
	printf("\nEnter the elements: ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&ele);
		Insert(ele);
	}
	printf("/nDeleted elements:");
	for(i=0;i<len;i++)
	{
		printf("/t%d",deleteMin());
	}
	printf("\n");
	return 0;
}
//b171152	
