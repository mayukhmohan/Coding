#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
	struct node *prev;
};
struct node *head=NULL;
void insert(int);
void sort(void);
void print(void);
int main()
{
	int n,i,x;
	printf("How many data you want to insert?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data: ");
		scanf("%d",&x);
		insert(x);
	}
	printf("\nBefore sorting...\n");
	print();
	sort();
	printf("\nAfter sorting....\n");
	print();
	return 0;
}
void insert(int x)
{
	struct node *temp,*p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;
	temp=head;
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
		p->prev=temp;
	}
}
void print(void)
{
	struct node *temp;
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void sort(void)
{
	int x;
	struct node *p=head,*q=NULL;
	p=p->next;
	while(p!=NULL)
	{
		q=p;
		while(q->prev!=NULL && (q->data<(q->prev)->data))
		{
			x=q->data;
			q->data=(q->prev)->data;
			(q->prev)->data=x;
			q=q->prev;
		}
		p=p->next;
	}
}












