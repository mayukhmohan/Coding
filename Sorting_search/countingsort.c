#include<stdio.h>
void countingsort(int arr[],int n,int max)
{
	int i,count[max+1],sortedip[n+1];
	for(i=0;i<=max;i++)
	{
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		++count[arr[i]];
	}
	/*for(i=0;i<=max;i++)
	{
		printf("%d\t",count[i]);
	}*/
	for(i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	/*printf("\n");
		for(i=0;i<=max;i++)
	{
		printf("%d\t",count[i]);
	}*/
	for(i=0;i<n;i++)
	{
		sortedip[count[arr[i]]]=arr[i];
		count[arr[i]]--;
	}
	printf("\n");
	for(i=1;i<n+1;i++)
	{
		printf("%d\t",sortedip[i]);
	}
}
void main()
{
	int arr[10],i,max;
	printf("populate your array:\n");
	for(i=0;i<10;i++)
	{
		printf("enter data:");
		scanf("%d",&arr[i]);
	}
	max=arr[0];
	for(i=1;i<10;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
	}
	printf("\nafter doing counting sort:\n");
	countingsort(arr,10,max);
}
