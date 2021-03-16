#include <stdio.h>
typedef enum { false, true } bool;
bool findPartiion (int*,int);
int main()
{
  long int t,x,n;
  scanf("%ld",&t);
  while(t--)
  {
  	scanf("%ld%ld",&x,&n);	
  	long int i,arr[n-1],ans[n];
  	for(i=1;i<=n;i++)
  	{
	  	if(i<x)
	  	{
	  		arr[i-1]=i;
		}
		else if(i>x)
	  	{
	  		arr[i-2]=i;
		}
	}
	for(i=0;i<n;i++)
  	{
	  	ans[i]=-1;
	}
	ans[x-1]=2;
	for(i=0;i<n;i++)
	{
		printf("%ld ",ans[i]);
	}
	printf("\n");
	for(i=0;i<n-1;i++)
	{
		printf("%ld",arr[i]);
	}
  }
  return 0;
}
bool findPartiion (int arr[], int n)
{
    int sum = 0;
    int i, j;
    for (i = 0; i < n; i++)
      sum += arr[i];
    if (sum%2 != 0)  
       return false;
    bool part[sum/2+1][n+1];
    for (i = 0; i <= n; i++)
      part[0][i] = true;
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;      
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
     for (i = 0; i <= sum/2; i++)  
     {
       for (j = 0; j <= n; j++)  
          printf ("%4d", part[i][j]);
       printf("\n");
     } 
     return part[sum/2][n];
}     

