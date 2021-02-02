#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* pre;
    int e;
    struct node* next;
};
struct node* push(struct node *head,int ele)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));

	if(nn==NULL)
	{
		printf("element cannot be added");
	}
	else
	{
		if(head==NULL)
		{
			nn->e=ele;
			nn->pre=NULL;
			nn->next=NULL;
			head=nn;
		}
		else
		{
			nn->e=ele;
			nn->pre=NULL;
			nn->next=head;
			head=nn;
		}
	}
	return head;
}
struct node* pop(struct node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		if(head->next==NULL)
			head=NULL;
		else
		{
		head->next->pre=NULL;
		head=head->next;
		}
	}
	return head;
}
struct node* display(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		while(tmp!=NULL)
		{
			printf("%d\n",tmp->e);
			tmp=tmp->next;
		}
	}
	return head;
}
void main()
{
    struct node *head=NULL;
    int op;
    
    do{
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("enter your choice:\n");
    	scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
            	int ele;
				printf("enter element to push:");
				scanf("%d",&ele);
                head=push(head,ele);
                break;
            }
        case 2:
        	{
        		head=pop(head);
        		break;
			}
		case 3:
			{
				head=display(head);
				break;	
			}		
        case 4:
        	{
        		exit(0);
			}
        default:
            {
                printf("enter valid option\n");
            }
        }
    }
    while(op!=4);
}
