#include<stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node* next;
};
struct node* insertbegin(struct node *head)
{
   struct node *tmp;
   int ele;
   printf("element to enter:");
   scanf("%d",&ele);
   if(head==NULL)
   {
       head=(struct node*)malloc(sizeof(struct node));
       head->e=ele;;
       head->next=NULL;
   }
   else
   {
       tmp=(struct node*)malloc(sizeof(struct node));
       tmp->next=head;
       tmp->e=ele;
       head=tmp;
   }
   return head;
}
struct node* insertend(struct node *head)
{
	struct node *nn;
	struct node *tmp;
	int ele;
	tmp=head;
	printf("enter the element:");
	scanf("%d",&ele);
	nn=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
   {
       head=(struct node*)malloc(sizeof(struct node));
       head->e=ele;;
       head->next=NULL;
   }
   else
   {
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=nn;
	nn->next=NULL;
	nn->e=ele;
}
	return head;
}
struct node* insertpos(struct node *head)
{
	int c=1,ele,n,count=1;
	struct node *tmp;
	struct node *nn;
	tmp=head;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter the position:");
	scanf("%d",&n);
	printf("enter the element:");
	scanf("%d",&ele);
	 if(head==NULL)
   {
       head=(struct node*)malloc(sizeof(struct node));
       head->e=ele;;
       head->next=NULL;
   }
   else
   {
   
	nn->e=ele;
	while(tmp->next!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
	tmp=head;
	if(n<count)
	{
	
		while(c<n-1)
		{
			tmp=tmp->next;
			c++;
	
		}
	}
	else
		printf("invalid position\n");
	nn->next=tmp->next;
	tmp->next=nn;
}
	return head;
}
struct node* delbegin(struct node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	head=head->next;
	}
	return head;
}
struct node* delend(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(tmp->next->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=NULL;
	return head;
}
}

struct node* delele(struct node *head)
{
	struct node *tmp=head,*tmp1=head;
	int ele,f=0;
	printf("enter the element to delete:");
	scanf("%d",&ele);
	if(head==NULL)
		printf("list is empty\n");
	else
	{	
	while(tmp!=NULL)
	{
		if(tmp->e==ele)
		{
	
			f=1;
			break;
		}
		tmp=tmp->next;
	}
	if(f==1)
	{
		if(head->e==ele)
		{
			head=head->next;
		}
		else 
		{
			while(tmp1->next!=tmp)
			{
				tmp1=tmp1->next;
			}
			tmp1->next=tmp->next;
		}
	}
	else
	{
		printf("element not found\n");
	}
}
	return head;	
}

struct node* search(struct node *head)
{
	struct node *tmp=head;
	int ele,f;
	printf("enter element to search:");
	scanf("%d",&ele);
	f=0;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(tmp!=NULL)
	{
		if(tmp->e==ele)
		{
			f=1;
			break;
		}
		else
		{
			tmp=tmp->next;
		}
	}
	if(f==1)
	{
		printf("element found\n");
	}
	else
		printf("element not found\n");
	}
	return head;
}
struct node* display(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
		printf("list is empty\n");
		else
		{
		
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->e);
		tmp=tmp->next;
	}}
	return head;
}
void main()
{
    struct node *head=NULL;
    int op;
    
    do{
        printf("1.Insert in the beginning\n2.Insert at the end\n3.Insert at a position\n4.Del at the beginning\n5.del at the end\n6.Delete an element\n7.find element\n8.Display\n9.exit\n");
        printf("enter your choice:\n");
    	scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                head=insertbegin(head);
                break;
            }
        case 2:
        	{
        		head=insertend(head);
        		break;
			}
        case 3:
        	{
        		head=insertpos(head);
        		break;
			}
		case 4:
			{
				head=delbegin(head);
				break;
			}
		case 5:
			{
				head=delend(head);
				break;
			}	
		case 6:
			{
				head=delele(head);
				break;
			}
		case 7:
			{
				head=search(head);
				break;
			}
		case 8:
			{
				head=display(head);
				break;
			}		
        case 9:
            {
            exit(0);
            }
        default:
            {
                printf("enter valid option\n");
            }
        }
    }
    while(op!=9);
}
