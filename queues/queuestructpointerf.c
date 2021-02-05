//b171152
//queues using structure pointer with functions

#include<stdio.h>
struct queue
{
    int a[20];
    int rear;
    int front;
    int size;
};
int enqueue(struct queue *q)
{

                if(q->rear==q->size-1)
                    printf("Queue is full\n");
                else
                {
                    q->rear++;
                    scanf("%d",&q->a[q->rear]);
                }
                return 0;
}
int dequeue(struct queue *q)
{
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else{
        q->front++;
        printf("%d\n",q->a[q->front]);
    }
    return 0;
}
main()
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    int opt;
    q->rear=-1;
    q->front=-1;
    printf("enter the size of array:");
    scanf("%d",&q->size);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        printf("Your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            {
                enqueue(q);
                break;
            }
        case 2:
            {
                dequeue(q);
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
