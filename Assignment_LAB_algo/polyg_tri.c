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
float pt(struct point *arr,int i,int j)
{
	if(j < i+2)
	{
		return 0;
	}
	int k;
	float result = MAX;
	for(k=i+1;k<=j-1;k++)
	{
		result = min(result,(pt(arr,i,k)+pt(arr,k,j)+cost(arr,i,j,k)));
	}
	return result;
}
void main()
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
	printf("\nMinimum cost is %f\n",pt(arr,0,n-1));
}
