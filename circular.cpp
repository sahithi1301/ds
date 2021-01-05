#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node *next;
};
struct node* inserthead(struct node *head)
{
	struct node *tmp=head;
	struct node *nn;
	int ele;
	printf("enter an element to add:");
	scanf("%d",&ele);
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->e=ele;
		head->next=head;
	}
	else
	{
		while(tmp->next!=head)
		{
			tmp=tmp->next;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=head;
		head=nn;
		tmp->next=head;
	}
	return head;
}
struct node* insertend(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		head=inserthead(head);
	}
	else
	{
		struct node *nn;
		int ele;
		printf("enter an element to add:");
		scanf("%d",&ele);
		nn=(struct node*)malloc(sizeof(struct node));
		while(tmp->next!=head)
		{
			tmp=tmp->next;
		}
		tmp->next=nn;
		nn->next=head;
		nn->e=ele;
	}
	return head;
}
struct node* insertpos(struct node *head)
{
	struct node *tmp=head,*nn;
	int c=0,count=1,pos;
	printf("enter the position to add:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		head=inserthead(head);
	}
	else
	{
	while(tmp->next!=head)
	{
		c++;
		tmp=tmp->next;
	}
	c++;}
	tmp=head;
	if(pos!=1 && pos<=c)
	{
		int ele;
		printf("enter an element to add:");
		scanf("%d",&ele);
		while(count<pos-1)
		{
			tmp=tmp->next;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		nn->next=tmp->next;
		nn->e=ele;
		tmp->next=nn;
	}
	if(pos==c+1)
	{
		head=insertend(head);
	}
	return head;
}

struct node* display(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(tmp->next!=head)
	{
		printf("%d\n",tmp->e);
		tmp=tmp->next;
	}
	printf("%d\n",tmp->e);}
}
void find(struct node *head)
{
	struct node *tmp=head;
	int ele,f=0;
	printf("enter the element to find:");
	scanf("%d",&ele);
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(tmp->next!=head)
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
		if(f==0)
		{
			if(tmp->e==ele)
			{
				f=1;
			}
			else
				printf("\nelement not found\n\n");
		}
		if(f==1)
		{
			printf("\nelement is found\n\n");
		}
	}
}
struct node* del_head(struct node *head)
{
	if(head==NULL)
	{
		printf("\nlist is empty\n");
	}
	else
	{
		struct node *tmp=head;
		while(tmp->next!=head)
		{
			tmp=tmp->next;
		}
		if(head==head->next)
		{
			head=NULL;
		}
		else
		{
			head=head->next;
			tmp->next=head;
		}
	}
	return head;
}
struct node* del_end(struct node *head)
{
	struct node *tmp=head,*tmp1=head;
	if(head==NULL)
	{
		printf("list is empty\n\n");
	}
	else if(head==head->next)
	{
		head=del_head(head);
	}
	else
	{
		while(tmp->next!=head)
		{
			tmp=tmp->next;
		}
		while(tmp1->next!=tmp)
		{
			tmp1=tmp1->next;
		}
		tmp1->next=head;
	}
	return head;
}
struct node* del_ele(struct node *head)
{
	struct node *tmp=head;
	int ele,f=0;
	printf("enter an element:");
	scanf("%d",&ele);
	if(head==NULL)
	{
		printf("list is empty\n\n");
	}
	else
	{
		while(tmp->next!=head)
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
		if(f==1 && tmp==head)
		{
			head=del_head(head);
		}
		else if(f==1)
		{
			struct node *tmp1=head;
			while(tmp1->next!=tmp)
			{
				tmp1=tmp1->next;
			}
			tmp1->next=tmp->next;
		}
		else if(f==0 && tmp->e==ele)
		{
			head=del_end(head);
		}
		else
		{
			printf("element not found\n\n");
		}
	}
	return head;
}
int main()
{
	struct node *head=NULL;
	int op;
	do
	{

		printf("1.Insert at head\n2.Insert at position\n3.Insert at end\n4.Del at head\n5.Delete an element\n6.Delete at end\n7.Fnd an element\n8.Display\n9.Exit\n\nEnter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					head=inserthead(head);
					break;
				}
			case 2:
				{
					head=insertpos(head);
					break;
				}
			case 3:
				{
					head=insertend(head);
					break;
				}
			case 4:
				{
					head=del_head(head);
					break;
				}
			case 5:
				{
					head=del_ele(head);
					break;
				}
			case 6:
				{
					head=del_end(head);
					break;
				}
			case 7:
				{
					find(head);
					break;
				}
			case 8:
				{
					display(head);
					break;
				}
			case 9:
				{
					exit(0);
				}
					
		}
	}
	while(op!=9);
	return 0;
}

