#include<stdio.h>
int catalan(int n)
{
	int i;
    if (n <= 1) return 1;
    int res = 0;
    for (i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
    return res;
}
int main()
{
	int i;
    for (i=0; i<10; i++)
        printf("%d ",catalan(i));
    return 0;
}
