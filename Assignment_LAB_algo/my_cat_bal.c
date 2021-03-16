#include<stdio.h>
#define MAX_SIZE 999999
int permutation = 0;
void printbalenced(int pos,int size,int start,int end)
{
	static char str[MAX_SIZE];
	if(end == size)
	{
		printf("%s \n",str);
		permutation++;
		return;
	}
	if(start<size)
	{
		str[pos] = '(';
		printbalenced(pos+1,size,start+1,end);
	}
	if(start>end)
	{
		str[pos] = ')';
		printbalenced(pos+1,size,start,end+1);
	}
}
int main()
{
	int n;
	printf("Enter for which numbers do you want to print?");
	scanf("%d",&n);
	printbalenced(0,n,0,0);
	printf("\n\n%d\n\n",permutation);
}
