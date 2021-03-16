#include<stdio.h>
#include<math.h>
#include<time.h>
long int no_of_operation=0;
long no_of_swaps=0;
long no_of_comparison=0;
long int select(long int*,long int,long int,long int);
long int partition(long int*,long int,long int,long int);
long int pivot(long int*,long int,long int);
long int partition7(long int*,long int,long int);
int main()
{
	long int i,j,ans,k,seq[12],sum=0,lb=5,ub=50000000;
	float c;
	FILE *fptr = fopen("readings_MOM_7.csv","w");
	FILE *fp = fopen("c_MOM_7.csv","w");
	FILE *p = fopen("time_MOM_7.csv","w");
	FILE *pt = fopen("comparison_MOM_7.csv","w");
	FILE *ptr = fopen("swap_MOM_7.csv","w");
	for(i=4;i<=16;i++)
	{
	    no_of_operation=0;
	    no_of_swaps=0;
		no_of_comparison=0;
		long int size=pow(2,i);
		long int arr[size];
		srand(time(0));
		printf("\nPopulating your array with Uniform Distribution...\n");
		for(j=0;j<size;j++)
		{
			arr[j]=lb + rand()%(ub-lb);
		}
        k = rand()%size;
		clock_t time;
    	time = clock();
		ans = select(arr,0,size-1,k);
		time = clock() - time;
		double time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nMoM took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f,", size,time_taken);
		printf("\nAfter Median of Medians:(Uniform Distribution)\n");
		/*for(j=0;j<size;j++)
		{
			printf("%d\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
		printf("\n%ldth element is %ld\n",k,ans);
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
			sum=0;
			for(k=0;k<12;k++)
			{
				seq[k]=lb + rand()%(ub-lb);
				sum+=seq[k];
			}
			arr[j]=sum/12;
		}
		time = clock();
		ans = select(arr,0,size-1,k);
		time = clock() - time;
		time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nMoM took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f\n", size,time_taken);
		printf("\nAfter Median of Medians:(Normal Distribution)\n");
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
	}
    fclose(fptr);
	fclose(fp);
	fclose(p);
	fclose(pt);
	fclose(ptr);

	/*long int arr[100];
	j=100;
	for(i=0;i<100;i++)
	{
		//printf("Enter Data: ");
		//scanf("%ld",&arr[i]);
		arr[i]=j;
		j--;
	}
	printf("Enter which position you want to select: ");
	scanf("%ld",&k);
	ans = select(arr,0,99,k);
	for(i=0;i<100;i++)
	{
		printf("%ld ",arr[i]);
	}*/
	//printf("\n%ldth element is %ld\n",k,ans);
	return 0;
}
long int select(long int *arr,long int l,long int r,long int index)
{
    long int i;
	if(l>=r)
	{
		return arr[l];
	}
	long int k,q = pivot(arr,l,r);
    q = partition(arr,l,r,q);
    k = q-l+1;
    if(index==k)
	{
		return arr[q];
	}
	else if(index<k)
    {
    	return select(arr,l,q-1,index);
	}
    else
    {
    	return select(arr,q+1,r,index-k);
	}
}
long int partition(long int *arr,long int l,long int r,long int pivotIndex)
{
    long int i;
    if(pivotIndex>r)
    {
        pivotIndex=r;
    }
    else if(pivotIndex<l)
    {
        pivotIndex=l;
    }
	if(r<=l)
	{
		return l;
	}
	else if(r>l)
	{
		long int t,x,i,j;
		no_of_operation++;
		t=arr[pivotIndex];
		arr[pivotIndex]=arr[r];
		arr[r]=t;
		x=arr[r];
		i=l-1;
		for(j=l;j<r;j++)
		{
		    no_of_operation++;
		    no_of_comparison++;
			if(arr[j]<=x)
			{
				no_of_swaps++;
				i++;
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
		no_of_operation++;
		no_of_swaps++;
		t=arr[i+1];
		arr[i+1]=arr[r];
		arr[r]=t;
		return i+1;
	}
}
long int pivot(long int *arr,long int l,long int r)
{
    long int i;
	long int subRight,median7,t;
    if((r - l)< 7)
    {
		return partition7(arr,l,r);
	}
    for(i=l;i<=r;i+=7)
    {
    	//no_of_operation++;
        subRight = i + 6;
        if(subRight > r)
		{
			subRight = r;
     	}
		median7 = partition7(arr, i, subRight);
		//no_of_operation++;
		//no_of_swaps++;
		t=arr[median7];
		arr[median7]=arr[l + (i - l)/7];
		arr[l + (i - l)/7]=t;
	}
    return select(arr, l, l + (r - l)/7, l + (r - l)/14);
}
long int partition7(long int *arr,long int l,long int r)
{
    long int i;
	if(l>=r)
	{
		return l;
	}
	long int j,key,length=r-l+1;
	for(i=1;i<length;i++)
	{
		//no_of_operation++;
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			//no_of_comparison++;
			//no_of_operation++;
			//no_of_swaps++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	return l+(r-l)/2;
}
