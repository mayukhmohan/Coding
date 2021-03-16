#include<stdio.h>
#include<math.h>
#include<time.h>
long int no_of_operation=0;
long no_of_swaps=0;
long no_of_comparison=0;
void quicksort(long int arr[],long int l,long int r)
{
	long int t,fp,sp;
	if((r-l)<1)
		return;
	fp=l+1;
	for(sp=l+1;sp<=r;sp++)
	{
		no_of_operation++;
		no_of_comparison++;
		if(arr[l]>arr[sp])
		{
			//no_of_operation++;
			no_of_swaps++;
			t=arr[sp];
			arr[sp]=arr[fp];
			arr[fp]=t;
			fp++;
		}
	}
	no_of_operation++;
	no_of_swaps++;
	t=arr[fp-1];
	arr[fp-1]=arr[l];
	arr[l]=t;
	quicksort(arr,l,fp-2);
	quicksort(arr,fp,sp-1);
}
void main()
{
	long int i,j,k,seq[12],sum=0,lb=5,ub=50000000;
	float c;
	FILE *fptr = fopen("readings_quicksort.csv","w");
	FILE *fp = fopen("c_quicksort.csv","w");
	FILE *p = fopen("time_quick.csv","w");
	FILE *pt = fopen("comparison_quick.csv","w");
	FILE *ptr = fopen("swap_quick.csv","w");
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
		quicksort(arr,0,size-1);
		time = clock() - time;
		double time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nQuickSort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f,", size,time_taken);
		printf("\nAfter Quick Sorting:(Uniform Distribution)\n");
		/*for(j=0;j<size;j++)
		{
			printf("%d\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
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
		quicksort(arr,0,size-1);
		time = clock() - time;
		time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nQuickSort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f\n", size,time_taken);
		printf("\nAfter Quick Sorting:(Normal Distribution)\n");
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
