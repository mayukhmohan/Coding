#include<stdio.h>
void shellsort(int arr[],int n)
{
	int i,j,gap,t;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			t=arr[i];
			for(j=i;j>=gap && arr[j-gap]>t;j-=gap)
			{
				arr[j]=arr[j-gap];
			}
			arr[j]=t;
		}
	}
}
void main()
{
	int arr[10],i;
	printf("populate your array:\n");
	for(i=0;i<10;i++)
	{
		printf("enter data:");
		scanf("%d",&arr[i]);
	}
	shellsort(arr,10);
	printf("after doing shell sort\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
}
