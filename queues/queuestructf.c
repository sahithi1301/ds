//b171152
//queues using structure with functions

#include<stdio.h>
struct queue
{
    int a[20];
    int rear;
    int front;
    int size;
};
struct queue enqueue(struct queue q)
{

                if(q.rear==q.size-1)
                    printf("Queue is full\n");
                else
                {
                    q.rear++;
                    scanf("%d",&q.a[q.rear]);
                }
                return q;
}
struct queue dequeue(struct queue q)
{
    if(q.front==q.rear)
        printf("Queue is empty\n");
    else{
        q.front++;
        printf("%d\n",q.a[q.front]);
    }
    return q;
}
main()
{
    struct queue q;
    int opt;
    q.rear=-1;
    q.front=-1;
    printf("enter the size of array:");
    scanf("%d",&q.size);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        printf("Your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            {
                q=enqueue(q);
                break;
            }
        case 2:
            {
                q=dequeue(q);
                break;
            }
        case 3:{
            printf("process terminated");
            break;
        }
        default:{
            printf("enter valid input");
            }

        }
    }
    while(opt!=3);
}
//b171152
