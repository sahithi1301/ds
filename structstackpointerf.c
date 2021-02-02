#include<stdio.h>
struct stack
{
    int a[5];
    int top;
    int max;
};
int push(struct stack *s)
{
    int ele;
    if(s->top==s->max-1)
        printf("stack is full\n");
    else
    {
        s->top++;
        scanf("%d",&ele);
        s->a[s->top]=ele;
    }
    return 0;
}
int pop(struct stack *s)
{
    int e;
    if(s->top==-1)
        printf("stack is empty\n");
    else
    {
        e=s->a[s->top];

        s->top--;
        printf("%d\n",e);
    }
    return 0;
}
void main()
{
    struct stack *s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->max=5;
    int opt;
    do
    {
        printf("1.Push\n2.Pop\n3.Exit\n");
        printf("enter your choice:");
        scanf("%d",&opt);
        switch(opt){
			case 1:{
				push(s);
				break;
			}
			case 2:{
				pop(s);
				break;
			}
			case 3:
				exit(0);
			default:{
				printf("Enter valid option.\n");
				break;
			}
		}


    }
    while(opt!=3)
    ;
}

