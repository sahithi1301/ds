#include<stdio.h>
struct queue
{
    int *a;
    int rear;
    int front;
    int size;
};
void main()
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    printf("enter the size of the array:");
    scanf("%d",&q->size);
    q->a=(int *)malloc(q->size*sizeof(int));
    int opt;
    q->rear=-1;
    q->front=-1;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
        printf("Your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            {
                if(q->rear==q->size-1)
                    printf("queue is  full\n");
                else
                {
                    q->rear++;
                    scanf("%d",&q->a[q->rear]);
                }
                break;
            }
        case 2:
            {
                if(q->front==q->rear)
                    printf("Queue is empty\n");
                else
                {
                    q->front++;
                    printf("%d\n",q->a[q->front]);
                }
                break;
            }
        case 3:
            {
                exit(0);
            }
        default:
            printf("enter valid number");
        }
    }
    while(opt!=3);
}
