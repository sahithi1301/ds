#include<stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node* next;
};
struct node* enqueue(struct node *head,int ele)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->e=ele;
	if(nn==NULL)
	{
		printf("element cannot be added");
	}
	else
	{
		if(head==NULL)
		{
			nn->next=NULL;
			head=nn;
		}
		else
		{
			nn->next=head;
			head=nn;
		}
	}
	return head;
}
struct node* dequeue(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
		}
		else
		{
			while(tmp->next->next!=NULL)
			{
				tmp=tmp->next;
			}
			tmp->next=NULL;
		}
	}
	return head;
}
struct node* display(struct node *head)
{
	struct node *tmp=head;
	if(tmp==NULL)
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
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("enter your choice:\n");
    	scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
            	int ele;
				printf("enter element to push:");
				scanf("%d",&ele);
                head=enqueue(head,ele);
                break;
            }
        case 2:
        	{
        		head=dequeue(head);
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
