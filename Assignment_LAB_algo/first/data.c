#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
	FILE *pt = fopen("uniform.csv","w");
	FILE *ptr = fopen("normal.csv","w");
	int i,k,arr[65536],sum=0,seq[12],lb=5,ub=50000000;
	srand(time(0));
	for(i=0;i<65536;i++)
	{
		arr[i]=lb + rand()%(ub-lb);
		fprintf(pt,"%d\n",arr[i]);
	}
	for(i=0;i<65536;i++)
	{
		sum=0;			
		for(k=0;k<12;k++)
		{
			seq[k]=lb + rand()%(ub-lb);				
			sum+=seq[k];
		}
		arr[i]=sum/12;
		fprintf(ptr, "%d\n", arr[i]);
	}
	fclose(pt);
	fclose(ptr);
	return 0;
}
