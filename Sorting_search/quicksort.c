#include<stdio.h>
void quicksort(int arr[],int l,int r)
{
	int t,fp,sp;
	if((r-l)<1)
		return;
	fp=l+1;
	for(sp=l+1;sp<=r;sp++)
	{
		if(arr[l]>arr[sp])
		{
			t=arr[sp];
			arr[sp]=arr[fp];
			arr[fp]=t;
			fp++;
		}
	}
	t=arr[fp-1];
	arr[fp-1]=arr[l];
	arr[l]=t;
	quicksort(arr,l,fp-2);
	quicksort(arr,fp,sp-1);
}
void main()
{
	int i,j=0,arr[500];
	printf("populate your array:-\n");
	for(i=500;i>=1;i--)
	{
		arr[j]=i;
		j++;
	}
	quicksort(arr,0,499);
	printf("after quicksorting your array ::\n");
	for(i=0;i<500;i++)
	{
		printf("%d\t",arr[i]);
	}
}
