#include<stdio.h>
#include<stdlib.h>
struct tnode 
{
	int e;
	struct tnode *left;
	struct tnode *right;
};
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
		struct tnode *tmp=root;
		struct tnode *nn;
		nn=(struct tnode*)malloc(sizeof(struct tnode));
		nn->left=NULL;
		nn->right=NULL;
		nn->e=ele;
		while(1)
		{
			if(tmp->e>ele)
			{
				if(tmp->left!=NULL)
				{
					tmp=tmp->left;
				}
				else
				{
					tmp->left=nn;
					break;
				}
			}
			else
			{
				
				if(tmp->right!=NULL)
				{
					tmp=tmp->right;
				}
				else
				{
					tmp->right=nn;
					break;
				}
			}
		}
	}
	return root;
}
struct tnode* find(struct tnode *root,int ele)
{
	struct tnode *tmp=root;
	int f=0;
	if(root==NULL)
	{
		printf("*****Tree is empty*****");
	}
	else
	{
		
		
		while(1)
		{
			if(tmp->e==ele)
			{
				f=1;
				break;
			}
			else if(tmp->e>ele)
			{
				if(tmp->left!=NULL)
				{
					tmp=tmp->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				
				if(tmp->right!=NULL)
				{
					tmp=tmp->right;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	if(f==1)
	{
		printf("element is FOUND\n");
		return tmp;
	}
	else
	{
		printf("element is NOT found\n");
		return NULL;
		
	}
}
struct tnode* del(struct tnode *root,int ele)
{
	struct tnode *tmp,*tmp1,*parent,*p;
	tmp1=find(root,ele);
	parent=tmp1;
	if(tmp1!=NULL)
	{
		if(tmp1->right!=NULL)
		{
			tmp=tmp1->right;
		}
	}
	else
	{
		printf("cannot delete element\n");
	}
	while(tmp->left!=NULL)
	{
		p=tmp;
		tmp=tmp->left;
	}
	tmp1->e=tmp->e;
	p->left=tmp->right;
	return root;
}
void preorder(struct tnode* root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->e);
		preorder(root->left);
		preorder(root->right);
	}
} 
void postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->e);
	}
}
void inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->e);
		inorder(root->right);
	}
}
int main()
{
	struct tnode *root=NULL,*tmp;
	int op,ele;
	do
	{
		printf("1.Insert\n2.Find\n3.Delete\n4.Preorder\n5.Inorder\n6.Postorder\n7.Exit\n\n");
		printf("enter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter element you want to add:");
				scanf("%d",&ele);
				root=insert(root,ele);
				break;
			case 2:
				printf("enter the element you want to find:");
				scanf("%d",&ele);
				tmp=find(root,ele);
				break;
			case 3:
				printf("enter the element you want to delete:");
				scanf("%d",&ele);
				root=del(root,ele);
				break;
			case 4:
				preorder(root);
				printf("\n\n");
				break;
			case 5:
				inorder(root);
				printf("\n\n");
				break;
			case 6:
				postorder(root);
				printf("\n\n");
				break;
			case 7:
				exit(0);
			default:
				printf("enter valid inputs");
				break;
		}
	}
	while(op!=7);
}
