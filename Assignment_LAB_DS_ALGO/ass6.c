#include<stdio.h>
#include<stdlib.h>
int binarycount=0;
int bstcount=0;
struct node
{
	int data,height;
	struct node *left;
	struct node *right;	
};
void mergesort(int *,int,int);
void max_heapify(int *,int,int);
void build_max_heap(int *,int);
void heapsort(int *,int);
void bs_rec(int *,int,int,int);
void merge(int *,int,int,int);
struct node* insert(struct node *,int);
int max(int,int);
int getBalance(struct node *);
int height(struct node *);
struct node *leftRotate(struct node *);
struct node *rightRotate(struct node *);
void inorder(struct node *);
void bstsearch(struct node*,int);
int main()
{
	int i,a[100],b[100],choice,option;
	struct node *root=NULL;
	for(i=0;i<100;i++)
	{
		a[i]=rand()%1000;
	}
	printf("Your array A is like....\n");
	for(i=0;i<100;i++)
	{
		printf("%d\t",a[i]);
	}
	for(i=0;i<100;i++)
	{
		b[i]=a[i];
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
		root=insert(root,a[i]);
	}
	printf("\nWhich Sort Do you want?\n1.MergeSort\n2.HeapSort\nYour Option:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			mergesort(b,0,99);
			break;
		case 2:
			build_max_heap(b,100);
			heapsort(b,100);
			break; 
	}
	printf("After sorting your array B is like....");
	for(i=0;i<100;i++)
	{
		printf("%d\t",b[i]);
	}
	printf("\n");
	printf("Your INORDER Tree traversal.....");
	inorder(root);
	printf("\n");
	printf("Put the value you want to search: ");
	scanf("%d",&choice);
	bs_rec(b,0,99,choice);
	bstsearch(root,choice);
	printf("\nBinary Search Tree comparison %d.\nBinary Search comparison %d.",
	bstcount,binarycount);
	printf("\nheight l %d and height r %d",height(root->left),height(root->right));
	return 0;
}
struct node *insert(struct node *root,int x)
{
    int balance;
    if(root==NULL)
    {
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        p->height=1;
        root=p;
        return root;
    }
    else if(x<root->data)
    {
        root->left=insert(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    else
        return root;
    root->height=1+max(height(root->left),height(root->right));
    balance=getBalance(root);
    //Left Left case
    if(balance>1 && x<root->left->data)
    {
        return rightRotate(root);
    }
    else if(balance<-1 && x>root->right->data)    //Right Right case
    {
        return leftRotate(root);
    }
    else if(balance>1 && x>root->left->data)//Left Right Case
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance<-1 && x<root->right->data)//Right Left case
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct node *leftRotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T=y->left;
    y->left=x;
    x->right=T;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
struct node *rightRotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T=x->right;
    x->right=y;
    y->left=T;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int getBalance(struct node *root)
{
    if(root==NULL)
        return 0;
    return (height(root->left)-height(root->right));
}
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
void max_heapify(int *arr,int index,int size)
{
	int l,r,largest;
	l=2*index+1;
	r=2*index+2;
	if((l<size) && (arr[index]<arr[l]))
	{
		largest=l;
	}
	else
	{
		largest=index;
	}
	if((r<size) && (arr[largest]<arr[r]))
	{
		largest=r;
	}
	if(largest!=index)
	{
		int temp;
		temp=arr[largest];
		arr[largest]=arr[index];
		arr[index]=temp;
		max_heapify(arr,largest,size);
	}
}
void build_max_heap(int *arr,int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
}
void heapsort(int *arr,int n)
{
	int i,temp,size=n;
	for(i=n-1;i>=1;i--)
	{
		temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		size--;
		max_heapify(arr,0,size);
	}
}
void mergesort(int *arr,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
void merge(int *arr,int p,int q,int rdash)
{
	int n1=q-p+1;
	int n2=rdash-q;
	int l[n1],r[n2],i,j,k=p;
	for(i=0;i<n1;i++)
	{
		l[i]=arr[p+i];
	}
	for(j=0;j<n2;j++)
	{
		r[j]=arr[q+j+1];
	}
	i=0;
	j=0;
	while((i+j)<(n1+n2))
	{
		if(i==n1)
		{
			arr[k]=r[j];
			j++;
			k++;
		}
		else if(j==n2)
		{
			arr[k]=l[i];
			i++;
			k++;
		}
		else if(l[i]<=r[j])
		{
			arr[k]=l[i];
			k++;
			i++;
		}
		else if(l[i]>r[j])
		{
			arr[k]=r[j];
			k++;
			j++;
		}
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void bs_rec(int arr[],int l,int u,int key)
{
	int mid;
	if(l>u) 
	{
		printf("search is unsuccessful\n"); 
		return;
	}
	mid=(l+u)/2;
	if(arr[mid]==key)
	{
		binarycount++;
		printf("search is successful\n");
	}
	else if(key>arr[mid])
	{
		binarycount++;
		bs_rec(arr,mid+1,u,key);
	}
	else
	{
		binarycount++;
		bs_rec(arr,l,mid-1,key);
	}
}
void bstsearch(struct node* root,int x)
{
	if(root == NULL)
    {
		printf("search is unsucessful\n");
	}
	else if(root->data == x)
	{
		bstcount++;
		printf("search is sucessful\n");
	}
	else if(x <= root->data)
	{
		bstcount++;
		bstsearch(root->left,x);
	}
	else
	{
		bstcount++;
		bstsearch(root->right,x);
	}
}
