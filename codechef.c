#include<stdio.h>
long int maxSubArraySum(long int*,long int);
long int max(long int,long int);
void main()
{
	long int t,i,n,k;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		long int arr[n],presum=0,f=0,sum2=0,sum3=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			presum+=arr[i];
			if(arr[i]<0)
			{
				f=1;
			}
		}
		if(f==0)
		{
			printf("%ld\n",presum*k);
			continue;
		}
		if(k==1)
		{
			printf("%ld\n",maxSubArraySum(arr,n));
			continue;
		}
		long int subarr2[n*2],subarr3[n*3];
		for(i=0;i<n*2;i++)
		{
			subarr2[i]=arr[i%n];
		}
		sum2=maxSubArraySum(subarr2,n*2);
		if(k==2)
		{
			printf("%ld\n",sum2);
			continue;
		}
		for(i=0;i<n*3;i++)
		{
			subarr3[i]=arr[i%n];
		}
		sum3=maxSubArraySum(subarr3,n*3);
		if(sum2==sum3)
		{
			printf("%ld\n",sum3);
			continue;
		}
		else
		{
			printf("%ld\n",sum2+(k-2)*(sum3-sum2));
		}
	}
}
long int max(long int a,long int b) { return (a > b)? a : b; }
long int maxSubArraySum(long int a[],long int size)
{
   long int max_so_far = a[0];
   long int curr_max = a[0],i;
 	
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
