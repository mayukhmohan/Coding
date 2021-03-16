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
void print(void);
int main()
{
	char ch='a';
	int i,x;
	while(ch!='e')
	{
		printf("enter data: ");
		scanf("%d",&x);
		insert(x);
		print();
		printf("\npress \'e\' to exit::");
		scanf("%s",&ch);
	}
	return 0;
}
void insert(int x)
{
	int f=0;
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
	else if(x<temp->data)
	{
		p->next=temp;
		head=p;
		(p->next)->prev=p;
	}
	else if(x>temp->data && temp==head && temp->next==NULL)
    {
        temp->next=p;
        p->prev=temp;
    }
	else
	{
		while(temp->next!=NULL)
		{
			if(x>(temp->next)->data)
			{
				temp=temp->next;
			}
			else
			{
				f=1;
				break;
			}
		}
		if(temp!=head ||f==1)
		{
			p->next=temp->next;
			p->prev=temp;
			temp->next=p;
			if(p->next!=NULL)
			{
				(p->next)->prev=p;
			}
		}
	}
}
void print(void)
{
	struct node *temp;
	temp=head;
	printf("\n Your List is:\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
