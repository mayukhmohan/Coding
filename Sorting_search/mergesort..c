#include<stdio.h>
void merge(int [],int,int,int);
void mergesort(int arr[],int l,int r)
{
	int mid;
	if(r-l<1)
	{
		return;
	}
	else
	{
		mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
void merge(int arr[],int left,int mid,int right)
{
	int p,q,i=0,j=0,k=0;
	p=mid-left+1;
	q=right-mid;
	int l[p],r[q];
	for(k=0;k<p;k++)
	{
		l[k]=arr[left+k];
	}
	for(k=0;k<q;k++)
	{
		r[k]=arr[mid+1+k];
	}
	k=left;
	while((i+j)<(p+q))
	{
		if(i==p)
		{
			arr[k]=r[j];
			j++;
		}
		else if(j==q)
		{
			arr[k]=l[i];
			i++;
		}
		else if(l[i]<=r[j])
		{
			arr[k]=l[i];
			i++;
		}
		else
		{
			arr[k]=r[j];
			j++;
		}
		k++;
	}
}
void main()
{
	int arr[10],i;
	printf("populate your array\n");
	for(i=0;i<10;i++)
	{
		printf("enter data: ");
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,9);
	printf("after merging and sorting\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
}
