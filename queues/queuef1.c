//b171152
//queues using array with functions

#include<stdio.h>
#include<stdlib.h>
int enqueue(int a[],int rear,int size)
{
    if(rear==size-1)
        printf("Queue is full\n");
    else
    {
        rear++;
        scanf("%d",&a[rear]);
    }
    return rear;
}
int dequeue(int a[],int rear,int front)
{
    if(front==rear)
        printf("Queue is empty\n");
    else
    {
        front++;
        printf("%d\n",a[front]);
    }
    return front;
}
void main()
{
    int a[20],size,rear,front,opt;
    rear=-1;
    front=-1;
    printf("size of the array");
    scanf("%d",&size);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        printf("Your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            {
              rear=enqueue(a,rear,size);
              break;
            }
        case 2:
            {
                front=dequeue(a,rear,front);
                break;
            }
        case 3:
            {
                printf("process terminated\n");
                break;
            }
        default:
            {
                printf("enter valid input\n");
                break;
            }
        }
    }
    while(opt!=3);
}
//b171152
