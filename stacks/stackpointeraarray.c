//b171152
//stacks without functions (structure with pointer array)

#include<stdio.h>
struct stack
{
    int *a;
    int top;
    int max;
};
main()
{
    struct stack *s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    printf("enter the size of the array:");
    scanf("%d",&s->max);
    s->a=(int*)malloc(s->max*sizeof(int));
    int opt,ele;
    do
    {
        printf("1.Push\n2.Pop\n3.Exit\n");
        printf("enter your choice:");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                {
                    if(s->top==s->max-1)
                        printf("stack is full\n");
                    else
                    {
                        s->top++;
                        scanf("%d",&ele);
                        s->a[s->top]=ele;
                    }
                    break;
                }
            case 2:
                {
                    if(s->top==-1)
                        printf("stack is empty\n");
                    else
                    {
                        printf("%d\n",s->a[s->top]);
                        s->top--;
                    }
                    break;
                }
            case 3:
                {
                    printf("process terminated");
                    break;
                }
            default:{
                printf("enter valid inputs");
                break;
            }

        }
    }
    while(opt!=3)
    ;
}
//b171152



