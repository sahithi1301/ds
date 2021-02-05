//b171152
//implementation of trees without order

#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	struct tnode *left;
	int e;
	struct tnode *right;
};
struct queue
{
	int f,r;
	struct tnode *a[20];
};
struct queue *q;
struct queue* enqueue(struct queue *q,struct tnode *ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}
struct tnode* dequeue(struct queue *q)
{
	q->f++;
	return q->a[q->f];
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	return 0;
}
struct tnode* insert(struct tnode *root,int ele)
{
	if(root==NULL)
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{

		struct tnode *tmp,*tmp1;
		tmp=(struct tnode*)malloc(sizeof(struct tnode));
		tmp->e=ele;
		tmp->right=NULL;
		tmp->left=NULL;

		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{

			tmp1=dequeue(q);
			if(tmp1->left!=NULL)
			{
				q=enqueue(q,tmp1->left);
			}
			else
				break;
			if(tmp1->right!=NULL)
			{
				q=enqueue(q,tmp1->right);
			}
			else
				break;

		}
		if(tmp1->left==NULL){

			tmp1->left=tmp;
			}
		else{

			tmp1->right=tmp;
			}

	}
	return root;
}
void print(struct tnode *root)
{
	if(root==NULL)
	{
		printf("Tree is empty");
	}
	else
	{
		struct tnode *tmp1;

		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			tmp1=dequeue(q);
			if(tmp1->left!=NULL)
			{
				q=enqueue(q,tmp1->left);
			}

			if(tmp1->right!=NULL)
			{
				q=enqueue(q,tmp1->right);
			}
			printf("%d\t",tmp1->e);
	}
	printf("\n");
}
}
struct tnode* finde(struct tnode *root,int ele)
{
	struct tnode *tmp1;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			tmp1=dequeue(q);
			if(tmp1->left!=NULL)
			{
				q=enqueue(q,tmp1->left);
			}
			if(tmp1->right!=NULL)
			{
				q=enqueue(q,tmp1->left);
			}
			if(tmp1->e==ele)
			{
				return tmp1;
			}
		}
}
struct tnode* findLast(struct tnode *root)
{
	struct tnode *tmp2;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
			q=enqueue(q,root);
		while(!isempty(q))
		{
			tmp2=dequeue(q);
			if(tmp2->left!=NULL)
			{
				q=enqueue(q,tmp2->left);
			}

			if(tmp2->right!=NULL)
			{
				q=enqueue(q,tmp2->right);
			}
	}
	return tmp2;
}
struct tnode* findparent(struct tnode *root,struct tnode *tmp)
{
	struct tnode *k;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			k=dequeue(q);

			if(k->left==tmp)
			{
				return k;
			}
			else
			{
				if(k->left!=NULL)
				{
					q=enqueue(q,k->left);
				}

			}
			if(k->right==tmp)
			{
				return k;
			}
			else
			{
				if(k->right!=NULL)
				{
					q=enqueue(q,k->right);
				}
			}
	}
}
int del(struct tnode *root)
{
    struct tnode *tmp1,*tmp2;
	if(root==NULL)
	{
		printf("element cannot be removed");
	}
	else
	{
		int ele;
		struct tnode *tmp;
		printf("what element you want to delete:");
		scanf("%d",&ele);
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		tmp1=finde(root,ele);
		tmp2=findLast(root);
		tmp=findparent(root,tmp2);
		tmp1->e=tmp2->e;
		if(tmp->left==tmp2)
			tmp->left=NULL;
		else
			tmp->right=NULL;
	}
}

int main()
{
	struct tnode *root=NULL;
	int op,ele;
	do
	{
		printf("1.Insert\n2.Print\n3.Exit\n");
        printf("enter your choice:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                printf("enter the element to be added:");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            }
        case 2:
            {
                print(root);
                break;
            }
        case 3:
            {
            	del(root);
				break;
			}
        case 4:
            {
                exit(0);
            }
        default:
            printf("enter valid input");
        }
	}
	while(op!=4);
	return 0;
}
//b171152
