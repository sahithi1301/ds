//b171152
//stacks with functions(simple array) 

#include<stdio.h>
int size=5;
int a[20];
int push(int top,int a[])
{
    if(top==size-1)
    {
        printf("stack is full\n");
    }
    else
    {
        top++;
        printf("enter an element:");
        scanf("%d",&a[top]);
    }
    return(top);
}
int pop(int top,int a[])

{
    if(top==size)
        top--;
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("%d\n",a[top]);
        top=top-1;
    }
    return(top);
}
void main()
{

    int top=-1,opt;
    int a[5];
	int size=5;
    do
    {
    printf("1.Push\n2.Pop\n3.Exit\n");
    printf("enter your choice:");
    scanf("%d",&opt);
   switch(opt){
        case 1 :
            top=push(top,a);
            break;
        case 2 :
            top=pop(top,a);
            break;
        case 3 :
            printf("process terminated");
        break;
        default :
            printf("enter valid input\n");
   }
}
while(opt!=3)
;
}
//b171152
