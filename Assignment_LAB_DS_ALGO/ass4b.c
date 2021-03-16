#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,exp;
	struct node *next,*prev;
};
void insert(struct node **,int,int);
void sort(struct node **);
void print(struct node **);
void add(struct node **,struct node **);
void subtract(struct node **,struct node **);
void mult(struct node **,struct node **);
int main()
{
	struct node *h1=NULL,*h2=NULL;
	int i,n,c,e;
	printf("how many members do you want to insert for first polynomial?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coefficient:");
		scanf("%d",&c);
		printf("enter exponent:");
		scanf("%d",&e);
		insert(&h1,c,e);
	}
	sort(&h1);
	printf("\nYour expression is-----\n");
	print(&h1);
	printf("\nhow many members do you want to insert for second polynomial?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coefficient:");
		scanf("%d",&c);
		printf("enter exponent:");
		scanf("%d",&e);
		insert(&h2,c,e);
	}
	sort(&h2);
	printf("\nYour expression is-----\n");
	print(&h2);
	add(&h1,&h2);
	subtract(&h1,&h2);
	mult(&h1,&h2);
	return 0;
}
void insert(struct node **p,int x,int y)
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->coeff=x;
	temp->exp=y;
	temp->next=NULL;
	temp->prev=NULL;
	q=*p;
	if(*p==NULL)
	{
		*p=temp;
	}
	else
	{
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=temp;
		temp->prev=q;
	}
}
void sort(struct node **head)
{
	int x,y;
	struct node *p=*head,*q=NULL;
	p=p->next;
	while(p!=NULL)
	{
		q=p;
		while(q->prev!=NULL && (q->exp>(q->prev)->exp))
		{
			x=q->exp;
			y=q->coeff;
			q->exp=(q->prev)->exp;
			q->coeff=(q->prev)->coeff;
			(q->prev)->exp=x;
			(q->prev)->coeff=y;
			q=q->prev;
		}
		p=p->next;
	}
}
void print(struct node **p)
{
	struct node *q=*p;
	printf("\n");
	while(q!=NULL)
	{
		printf("%dX^%d\t",q->coeff,q->exp);
		q=q->next;
	}
}
void add(struct node **l,struct node **r)
{
	int x;
	struct node *head=NULL,*lptr=*l,*rptr=*r;
	while(lptr!=NULL && rptr!=NULL)
	{
		if(lptr->exp==rptr->exp)
		{
			x=lptr->coeff+rptr->coeff;
			insert(&head,x,lptr->exp);
			lptr=lptr->next;
			rptr=rptr->next;
		}
		else if(lptr->exp>rptr->exp)
		{
			insert(&head,lptr->coeff,lptr->exp);
			lptr=lptr->next;
		}
		else
		{
			insert(&head,rptr->coeff,rptr->exp);
			rptr=rptr->next;
		}
	}
	if(lptr!=NULL && rptr==NULL)
	{
		while(lptr!=NULL)
		{
			insert(&head,lptr->coeff,lptr->exp);
			lptr=lptr->next;
		}
	}
	else
	{
		while(rptr!=NULL)
		{
			insert(&head,rptr->coeff,rptr->exp);
			rptr=rptr->next;
		}
	}
	printf("\nResult of addition\n");
	print(&head);
}
void subtract(struct node **l,struct node **r)
{
	int x;
	struct node *head=NULL,*lptr=*l,*rptr=*r;
	while(lptr!=NULL && rptr!=NULL)
	{
		if(lptr->exp==rptr->exp)
		{
			x=lptr->coeff-rptr->coeff;
			insert(&head,x,lptr->exp);
			lptr=lptr->next;
			rptr=rptr->next;
		}
		else if(lptr->exp>rptr->exp)
		{
			insert(&head,lptr->coeff,lptr->exp);
			lptr=lptr->next;
		}
		else
		{
			insert(&head,-rptr->coeff,rptr->exp);
			rptr=rptr->next;
		}
	}
	if(lptr!=NULL && rptr==NULL)
	{
		while(lptr!=NULL)
		{
			insert(&head,lptr->coeff,lptr->exp);
			lptr=lptr->next;
		}
	}
	else
	{
		while(rptr!=NULL)
		{
			insert(&head,-rptr->coeff,rptr->exp);
			rptr=rptr->next;
		}
	}
	printf("\nResult of subtraction\n");
	print(&head);
}
void mult(struct node **l,struct node **r)
{
	int c,e,f=0;
	struct node *head=NULL,*lptr=*l,*rptr=*r,*s,*s1=NULL,*temp;
	while(lptr!=NULL)
	{
		rptr=*r;
		f=0;
		while(rptr!=NULL)
		{
			f=0;
			c=rptr->coeff*lptr->coeff;
			e=rptr->exp+lptr->exp;
			s=head;
			while(s!=NULL && s->exp>=e)
			{
				if(s->exp==e)
				{
					s->coeff=s->coeff+c;
					f=1;
					break;
				}
				else if(s->next==NULL)
				{
					insert(&head,c,e);
					f=1;
					break;
				}
				s1=s;
				s=s->next;
			}
			if(f==0)
			{
				if(head==NULL)
				{
					temp=(struct node *)malloc(sizeof(struct node));
					temp->coeff=c;
					temp->exp=e;
					temp->next=head;
					temp->prev=head;
					head=temp;
				}
				else
				{
					temp=(struct node *)malloc(sizeof(struct node));
					temp->coeff=c;
					temp->exp=e;
					s->prev=temp;
					temp->next=s;
					temp->prev=s1;
					s1->next=temp;
				}
			}
			rptr=rptr->next;
		}
		lptr=lptr->next;
	}
	printf("\nResult of multiplication\n");
	print(&head);
}
