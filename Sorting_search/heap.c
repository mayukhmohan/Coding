#include<stdio.h>
void max_heapify(int *,int,int);
void build_max_heap(int *,int);
void heapsort(int *,int);
int main()
{
	int n,i;
	printf("Enter the sie of yoour array:");
	scanf("%d",&n);
	int arr[n];
	printf("Now populate your array:---\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Data:");
		scanf("%d",&arr[i]);
	}
	build_max_heap(arr,n);
	printf("Your Heap.....\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nHeap Sorting........\n");
	heapsort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
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
