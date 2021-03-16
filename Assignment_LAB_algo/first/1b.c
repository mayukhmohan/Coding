#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
long int no_of_operation=0;
long no_of_swaps=0;
long no_of_comparison=0;
void merge(long int [],long int,long int,long int);
void mergesort(long int arr[],long int l,long int r)
{
	int mid;
	if(r-l<1)
	{
		return;
	}
	else
	{
		mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
void merge(long int arr[],long int left,long int mid,long int right)
{
	int p,q,i=0,j=0,k=0;
	p=mid-left+1;
	q=right-mid;
	int l[p],r[q];
	for(k=0;k<p;k++)
	{
		l[k]=arr[left+k];
	}
	for(k=0;k<q;k++)
	{
		r[k]=arr[mid+1+k];
	}
	k=left;
	while((i+j)<(p+q))
	{
		if(i==p)
		{
			no_of_comparison++;
			no_of_operation++;
			no_of_swaps++;
			arr[k]=r[j];
			j++;
		}
		else if(j==q)
		{
			no_of_comparison++;
			no_of_operation++;
			no_of_swaps++;
			arr[k]=l[i];
			i++;
		}
		else if(l[i]<=r[j])
		{
			no_of_comparison++;
			no_of_swaps++;
			no_of_operation++;
			arr[k]=l[i];
			i++;
		}
		else
		{
			no_of_comparison++;
			no_of_swaps++;
			no_of_operation++;
			arr[k]=r[j];
			j++;
		}
		k++;
	}
}
void main()
{
	long int i,j,k,seq[12],sum=0,lb=5,ub=50000000;
	float c;
	FILE *fptr = fopen("readings_mergesort.csv","w");
	FILE *fp = fopen("c_mergesort.csv","w");
	FILE *p = fopen("time_merge.csv","w");
	FILE *pt = fopen("comparison_merge.csv","w");
	FILE *ptr = fopen("swap_merge.csv","w");
	for(i=4;i<=16;i++)
	{
		FILE *p1 = fopen("uniform.csv","r");
		FILE *p2 = fopen("normal.csv","r");
		no_of_operation=0;
		no_of_swaps=0;
		no_of_comparison=0;
		//srand(time(0));
		long int size=pow(2,i);
		long int arr[size];
		printf("\nPopulating your array with Uniform Distribution...\n");
		//printf("\nEnter Lower Bound: ");
		//scanf("%ld",&lb);
		//printf("\nEnter Upper Bound: ");
		//scanf("%ld",&ub);
		for(j=0;j<size;j++)
		{
			//arr[j]=lb + rand()%(ub-lb);
			fscanf(p1, "%d", &arr[j]);
		}
		clock_t time;
    	time = clock();
		mergesort(arr,0,size-1);
		time = clock() - time;
		double time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nmeregsort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f,", size,time_taken);
		printf("\nAfter merging and sorting:(Uniform Distribution)\n");
		/*for(j=0;j<size;j++)
		{
			printf("%d\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
		printf("\nNumber of Comparisons:%d\n",no_of_comparison);
		printf("\nNumber of Swaps:%d\n",no_of_swaps);
		fprintf(fptr, "%d,%d,", size,no_of_operation);
		fprintf(pt, "%d,%d,", size,no_of_comparison);
		fprintf(ptr, "%d,%d,", size,no_of_swaps);
		c=(float)no_of_operation/(size*log2(size));
	  	fprintf(fp, "%d,%f,", size,c);
		no_of_operation=0;
		no_of_swaps=0;
		no_of_comparison=0;
		printf("\nPopulating your array with Normal Distribution...\n");
		for(j=0;j<size;j++)
		{
			/*sum=0;
			for(k=0;k<12;k++)
			{
				seq[k]=lb + rand()%(ub-lb);
				sum+=seq[k];
			}
			arr[j]=sum/12;*/
			fscanf(p2, "%d", &arr[j]);
		}
    	time = clock();
		mergesort(arr,0,size-1);
		time = clock() - time;
		time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nmeregsort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f\n", size,time_taken);
		printf("\nAfter merging and sorting:(Normal Distribution)\n");
		/*for(j=0;j<size;j++)
		{
			printf("%d\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
		fprintf(fptr, "%d,%d\n", size,no_of_operation);
		fprintf(pt, "%d,%d\n", size,no_of_comparison);
		fprintf(ptr, "%d,%d\n", size,no_of_swaps);
		c=(float)no_of_operation/(size*log2(size));
		fprintf(fp, "%d,%f\n", size,c);
		printf("\n\n----------------------------------------\n\n");
		fclose(p1);
		fclose(p2);
	}
	fclose(fptr);
	fclose(fp);
	fclose(p);
	fclose(pt);
	fclose(ptr);
}
