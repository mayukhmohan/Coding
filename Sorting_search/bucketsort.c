#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	float data;
	struct node *next;
	struct node *prev;
};
int count=0;
void bucketsort(float *,int);
struct node* insert(struct node* ,float);
void insertion_sort(struct node *);
void concatenate(struct node **,float *);
void main()
{
	int i,n;
	printf("How many numbers do you want to insert, please mention: ");
	scanf("%d",&n);
	count=n;
	printf("\nInsert data which should lie between 0 to 1\n");
	float arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter Data: ");
		scanf("%f",&arr[i]);
	}
	bucketsort(arr,n);
	printf("\nAfter Bucket Sorting....\n");
	for(i=0;i<n;i++)
	{
		printf("%f ",arr[i]);
	}
}
void bucketsort(float *a,int n)
{
	int i;
	struct node *temp,*t,*b[n];
	for(i=0;i<n;i++)
	{
		b[i]=NULL;
	}
	for(i=0;i<n;i++)
	{
		b[(int)(n*a[i])] = insert(b[(int)(n*a[i])],a[i]);
		temp=b[(int)(n*a[i])]->next;
		t=b[(int)(n*a[i])];
		while(temp!=NULL)
		{
			temp->prev=t;
			temp=temp->next;
			t=t->next;
		}
		b[(int)(n*a[i])]->prev=NULL;
	}
	for(i=0;i<n;i++)
	{
		insertion_sort(b[i]);
	}
	concatenate(b,a);
}
struct node* insert(struct node *head,float x)
{
	if(head==NULL)
	{
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
		head=p;
	}
	else
	{
		head->next = insert(head->next,x);
	}
	return head;
}
void insertion_sort(struct node *head)
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	float key;
	struct node *t;
	struct node *temp=head->next;
	while(temp!=NULL)
	{
		key=temp->data;
		t=temp->prev;
		//printf("t->data=%d temp->data=%d key=%d\n",t->data,temp->data,key);
		while(t!=NULL && (t->data>key))
		{
			//printf("t->data=%d temp->data=%d key=%d\n",t->data,temp->data,key);
			t->next->data=t->data;
			t=t->prev;
		}
		if(t==NULL)
		{
			head->data=key;
		}
		else
		{
			t->next->data=key;
		}
		temp=temp->next;
	}
	//print_rec(head);
}
void concatenate(struct node **b,float *a)
{
	struct node *temp;
	int i,n,index=0;
	n=count;
	for(i=0;i<n;i++)
	{
		temp=b[i];
		if(b[i]==NULL)
		{
			continue;
		}
		else
		{
			while(temp!=NULL)
			{
				a[index]=temp->data;
				temp=temp->next;
				index++;
			}
		}
	}
}



