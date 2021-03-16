#include<stdio.h>
#include<math.h>
#define MAX 1000000.00
struct point
{
	int x,y;
};
float cost(struct point *arr,int i,int j,int k)
{
	float cost = sqrt((arr[i].x - arr[j].x)*(arr[i].x - arr[j].x) + (arr[i].y - arr[j].y)*(arr[i].y - arr[j].y))
	 + sqrt((arr[j].x - arr[k].x)*(arr[j].x - arr[k].x) + (arr[j].y - arr[k].y)*(arr[j].y - arr[k].y))
		+ sqrt((arr[i].x - arr[k].x)*(arr[i].x - arr[k].x) + (arr[i].y - arr[k].y)*(arr[i].y - arr[k].y));

	return cost;
}
float min(float x,float y)
{
	return (x < y) ? x : y;
}
void printSolution(int i,int j,int n,int s[][n])
{
if(j-i < 2)
	return;
printSolution(i,s[i][j],n,s);
printf("\n(%d, %d, %d)\n",i,s[i][j],j);
printSolution(s[i][j],j,n,s);
}
float pt_dp(struct point *arr,int n)
{
	if(n < 3)
		return 0;

	float dp[n][n]; //dp[i][j] stores the cost of triangulation from i to j
	//table[0][n-1] stores the result
	int s[n][n];
	int gap,i,j,k;
	for(gap = 0; gap < n; gap++)
	{
		for(i = 0, j = gap; j < n; i++,j++)
		{
			if(j < i + 2)
			{
				dp[i][j] = 0.0;
			}
			else
			{
				dp[i][j] = MAX;
				for(k = i+1; k <= j-1; k++)
				{
					float result = dp[i][k] + dp[k][j] + cost(arr,i,j,k);
					if(result < dp[i][j])
					{
						dp[i][j] = result;
						s[i][j] = k;
					}
				}
			}
		}
	}
	printf("\nSolution:\n");
	printSolution(0,n-1,n,s);
	return dp[0][n-1];
}
int main()
{
	int i,n;
	printf("Enter Number of Vertices:");
	scanf("%d",&n);
	struct point arr[n];
	printf("Enter Co-ordinates of Pentagon vertices.....\n");
	for(i=0;i<n;i++)
	{
		printf("%d point:-\n",i+1);
		printf("x value:");
		scanf("%d",&arr[i].x);
		printf("y value:");
		scanf("%d",&arr[i].y);
	}
	printf("\nMinimum cost is %f\n",pt_dp(arr,n));
	return 0;
}
