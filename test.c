#include<stdio.h>
void main()
{
	int a,d,cost;
	scanf("%d%d",&a,&d);
	cost = (d/50)*20;
	if(d%50!=0)
	{
		cost += 20;
	}
	if(a<12)
	{
		cost = cost * 0.5;
	}
	else if(a>=60)
	{
		cost = cost * 0.8;
	}
	printf("%d",cost);
}

