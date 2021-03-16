#include<stdio.h>
void main()
{
	int arr[10],i,j,t,pos;
	printf("populate your array\n");
	for(i=0;i<10;i++)
	{
		printf("enter data:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<10;i++)
	{
		pos=i;
		while(pos>0 && arr[pos]<arr[pos-1])
		{
			t=arr[pos];
			arr[pos]=arr[pos-1];
			arr[pos-1]=t;
			pos=pos-1;
		} 
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
}
