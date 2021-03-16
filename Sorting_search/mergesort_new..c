#include<stdio.h>
void mergesort(int *,int,int);
void merge(int *,int,int,int);
int main()
{
	int i,arr[10];
	printf("populate your array----\n");
	for(i=0;i<10;i++)
	{
		printf("enter data: ");
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
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
