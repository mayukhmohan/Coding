#include<stdio.h>
void bs_rec(int arr[],int l,int u,int key)
{
	int mid;
	if(l>u) 
	{
		printf("search is unsuccessful"); 
		exit (0);
	}
	mid=(l+u)/2;
	if(arr[mid]==key)
	{
		printf("successful");
	}
	else if(key>arr[mid])
	{
		bs_rec(arr,mid+1,u,key);
	}
	else
	{
		bs_rec(arr,l,mid-1,key);
	}
}
void main()
{
	int arr[10],i,x;
	printf("enter your array members:\n");
	for(i=0;i<10;i++)
	{
		printf("enter data");
		scanf("%d",&x);
		arr[i]=x;
	}
	printf("enter your key:");
	scanf("%d",&x);
	bs_rec(arr,0,9,x);
}
