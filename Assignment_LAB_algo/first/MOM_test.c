#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node
{
	float data;
	struct node *next;
	struct node *prev;
};
int count=0;
long int no_of_operation=0;
long no_of_swaps=0;
long no_of_comparison=0;
void bucketsort(float *,int);
struct node* insert(struct node* ,float);
void insertion_sort(struct node *);
void concatenate(struct node **,float *);
void main()
{
	long int i,j,k,lb=5,ub=50000000,max=-1,min=99999999;
	float seq[12],sum=0,c;
	FILE *fptr = fopen("readings_bucketsort.csv","w");
	FILE *fp = fopen("c_bucketsort.csv","w");
	FILE *p = fopen("time_bucket.csv","w");
	FILE *pt = fopen("comparison_bucket.csv","w");
	FILE *ptr = fopen("swap_bucket.csv","w");
	for(i=4;i<=6;i++)
	{
		FILE *p1 = fopen("uniform.csv","r");
		FILE *p2 = fopen("normal.csv","r");
		no_of_operation=0;
		no_of_swaps=0;
		no_of_comparison=0;
		//srand(time(0));
		long int n=pow(2,i);
		float arr[n];
		printf("\nPopulating your array with Uniform Distribution...\n");
		//printf("\nEnter Lower Bound: ");
		//scanf("%ld",&lb);
		//printf("\nEnter Upper Bound: ");
		//scanf("%ld",&ub);
		count=n;
		for(j=0;j<n;j++)
		{
			//arr[j]=(float)(lb + rand()%(ub-lb));
			fscanf(p1, "%f", &arr[j]);
		}
		for(j=0;j<n;j++)
		{
			printf("%f\t",arr[j]);
		}
		for(j=0;j<n;j++)
		{
			if(max<arr[j])
			{
				max=arr[j];
			}
			if(min>arr[j])
			{
				min=arr[j];
			}
		}
		//printf("\n%ld %ld\n\n",max,min);
		for(j=0;j<n;j++)
		{
			arr[j]=(float)((long int)(arr[j])-min)/(max-min);
		}
		for(j=0;j<10;j++)
		{
			printf("%f\t",arr[j]);
		}
		clock_t time = clock();
		bucketsort(arr,n);
		time = clock() - time;
		double time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nBucketSort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f,", n,time_taken);
		printf("\nAfter Bucket Sorting:(Uniform Distribution)\n");
		/*for(j=0;j<20;j++)
		{
			printf("%f\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
	  	fprintf(fptr, "%ld,%ld,", n,no_of_operation);
	  	fprintf(pt, "%ld,%ld,", n,no_of_comparison);
		fprintf(ptr, "%ld,%ld,", n,no_of_swaps);
		c=(float)no_of_operation/(n);
	  	fprintf(fp, "%d,%f,", n,c);
		no_of_operation=0;
		no_of_swaps=0;
		no_of_comparison=0;
		printf("\nPopulating your array with Normal Distribution...\n");
		for(j=0;j<n;j++)
		{
			/*sum=0;
			for(k=0;k<12;k++)
			{
				seq[k]=(float)(lb + rand()%(ub-lb));
				sum+=seq[k];
			}
			arr[j]=sum/12;*/
			fscanf(p2, "%f", &arr[j]);
		}
		for(j=0;j<n;j++)
		{
			if(max<arr[j])
			{
				max=arr[j];
			}
			if(min>arr[j])
			{
				min=arr[j];
			}
		}
		for(j=0;j<n;j++)
		{
			arr[j]=(float)((long int)(arr[j])-min)/(max-min);
		}
    	time = clock();
		bucketsort(arr,n);
		time = clock() - time;
		time_taken = ((double)time)/CLOCKS_PER_SEC;
		printf("\nRandomized QuickSort took %f seconds to execute \n", time_taken);
		fprintf(p, "%d,%f\n", n,time_taken);
		printf("\nAfter Bucket Sorting:(Normal Distribution)\n");
		/*for(j=0;j<20;j++)
		{
			printf("%f\t",arr[j]);
		}*/
		printf("\nNumber of Operations:%d\n",no_of_operation);
		fprintf(fptr, "%ld,%ld\n", n,no_of_operation);
		fprintf(pt, "%ld,%ld\n", n,no_of_comparison);
		fprintf(ptr, "%ld,%ld\n", n,no_of_swaps);
		c=(float)no_of_operation/(n);
		fprintf(fp, "%d,%f\n", n,c);
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
void bucketsort(float *a,int n)
{
	int i;
	struct node *temp,*t,*b[n];
	for(i=0;i<n;i++)
	{
		b[i]=NULL;
	}
	for(i=0;i<n;i++)
	{
		b[(int)(n*a[i])] = insert(b[(int)(n*a[i])],a[i]);
		temp=b[(int)(n*a[i])]->next;
		t=b[(int)(n*a[i])];
		while(temp!=NULL)
		{
			temp->prev=t;
			temp=temp->next;
			t=t->next;
		}
		b[(int)(n*a[i])]->prev=NULL;
	}
	for(i=0;i<n;i++)
	{
		insertion_sort(b[i]);
	}
	concatenate(b,a);
}
struct node* insert(struct node *head,float x)
{
	if(head==NULL)
	{
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
		head=p;
	}
	else
	{
		head->next = insert(head->next,x);
	}
	return head;
}
void insertion_sort(struct node *head)
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	float key;
	struct node *t;
	struct node *temp=head->next;
	while(temp!=NULL)
	{
		no_of_operation++;
		key=temp->data;
		t=temp->prev;
		while(t!=NULL && (t->data>key))
		{
			no_of_swaps++;
			no_of_operation++;
			no_of_comparison++;
			t->next->data=t->data;
			t=t->prev;
		}
		if(t==NULL)
		{
			no_of_swaps++;
			no_of_operation++;
			head->data=key;
		}
		else
		{
			no_of_swaps++;
			no_of_operation++;
			t->next->data=key;
		}
		temp=temp->next;
	}
	//print_rec(head);
}
void concatenate(struct node **b,float *a)
{
	struct node *temp;
	int i,n,index=0;
	n=count;
	for(i=0;i<n;i++)
	{
		temp=b[i];
		if(b[i]==NULL)
		{
			continue;
		}
		else
		{
			while(temp!=NULL)
			{
				a[index]=temp->data;
				temp=temp->next;
				index++;
			}
		}
	}
}
