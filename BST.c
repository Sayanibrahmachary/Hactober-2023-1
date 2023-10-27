#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *lc;
	struct node *rc;
};

struct node *s,*t,*root=NULL;

struct node *creat(int item)
{
	t=(struct node*)malloc(sizeof(struct node));
	t->data=item;
	t->lc=NULL;
	t->rc=NULL;
	
	if(root==NULL)
	{
		root=t;
	}
	return t;
}
struct node *insert(struct node *q,int item)
{
	if(q==NULL)
	{
		return creat(item);
	}
	else if(item<q->data)
	{
		q->lc=insert(q->lc,item);
	}
	else
	{
		q->rc=insert(q->rc,item);
	}
}
void inOrder(struct node *root1)
{
	if(root1!=NULL)
	{
		inOrder(root1->lc);
		printf("%d\t",root1->data);
		inOrder(root1->rc);		
	}
	else
	{
		printf("\nRoot is empty");
	}
}
void preOrder(struct node *root1)
{
	if(root1!=NULL)
	{
		printf("%d\t",root1->data);
		inOrder(root1->lc);
		inOrder(root1->rc);		
	}
	else
	{
		printf("\nRoot is empty");
	}
}
void postOrder(struct node *root1)
{
	if(root1!=NULL)
	{
		inOrder(root1->lc);
		inOrder(root1->rc);
		printf("%d\t",root1->data);	
	}
	else
	{
		printf("\nRoot is empty");
	}
}
int main() {
	int choice,value;
	do
	{
		printf("\nMenu:");
		printf("1) Insertion\n");
		printf("2) Preorder\n");
		printf("3) Inorder\n");
		printf("4) Postorder\n");
		printf("5) Exit from the list\n");
		
		printf("Enter you choose:\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
				printf("Enter the value:");
				scanf("%d",&value);
				insert(root,value);
				break;
			
			case 2:
				preOrder(root);
				break;
			
			case 3:
				inOrder(root);
				break;
			case 4:
				postOrder(root);
				break;
			
			case 5:
				printf("Exiting th program\n");
				break;
			
			default:
				printf("Invalid choice.Pleace try again");
				break;
		}
	}while(choice!=5);
	return 0;
}
