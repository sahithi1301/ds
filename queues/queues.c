//b171152
//queues using array without functions


#include<stdio.h>
main()
{
    int a[20];
    int rear,front;
    int opt,size;
    printf("enter the size of the array");
    scanf("%d",&size);
    rear=-1;
    front=-1;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        printf("Your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            {
              if(rear==size-1)
              {
                  printf("Queue is full\n");
              }
              else
              {
                  rear++;
                  scanf("%d",&a[rear]);
              }
              break;
            }
        case 2:
            {
                if(front==rear)
                    printf("Queue is empty\n");
                else
                {
                    front++;
                    printf("%d\n",a[front]);
                }
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
