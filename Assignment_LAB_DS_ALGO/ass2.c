#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    char data;
    struct node *next;
};
struct home
{
	int info;
	struct home *link;
};
struct node *top=NULL;
struct home *head=NULL;
void push(char x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}
void pushh(int x)
{
    struct home *temp;
    temp=(struct home *)malloc(sizeof(struct home));
    temp->info=x;
    temp->link=head;
    head=temp;
}
void pop(void)
{
    if(top==NULL)return;
    else
    {
        top=top->next;
    }
}
void poph(void)
{
    if(head==NULL)return;
    else
    {
        head=head->link;
    }
}
char topper(void)
{
    return(top->data);
}
int topperh(void)
{
    return(head->info);
}
int isempty(void)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
int isemptyh(void)
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
int hashigherprec(char,char);
int getweight(char);
int perform(char,int,int);
int isoperator(char);
void evalpostfix(char [][50],int);
int main()
{
	int n,f=0;
	char exp[50];
    printf("enter your infix expression:-----\n");
    gets(exp);
    printf("after doing postfixing:............\n");
    n=strlen(exp);
    int i,j=0,k=0;
	char post[50][50];
	for(i=0;i<n;i++)
	{
		if(exp[i]==' ' || exp[i]==',')
        {
        if(f==0)
		{
			post[j][k]='\0';
			j++;
			k=0;
		}
		else
		{
			f=0;
		}
        }
        else if(isoperator(exp[i]))
        {
            while(!isempty() && hashigherprec(topper(),exp[i]) && topper()!='(')
            {if(f==0)
                {
				post[j][k]=topper();
                k++;
                post[j][k]='\0';
                j++;
                k=0;
                pop();}
                else
                {
                	f=0;
				}
            }
            push(exp[i]);
        }
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
        	if(f==0)
        	{
				post[j][k]='\0';
        		j++;
        		k=0;
        	}
        	else
        	{
        		f=0;
			}
            while(topper()!='(' && !isempty())
            {
                post[j][k]=topper();
             	k++;
                post[j][k]='\0';
                j++;
                k=0;
                f=1;
			    pop();
            }
            pop();
        }
		else
		{
			post[j][k]=exp[i];
			k++;
		}
		if(i==n-1 && isempty())
		{
			post[j][k]='\0';
		}
	}
    while(!isempty())
    {
    if(f==0)
	{
		j++;
		k=0;
	}
    post[j][k]=topper();
    pop();
    k++;
    post[j][k]='\0';
    j++;
    k=0;
    }
    printf("\nyour postfix expression is here:\n");
    j++;
 for(i=0;i<j;i++)
	 {
	 printf("%s\t",post[i]);
   }   
    evalpostfix(post,j);
	return 0;
}
int isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')return 1;
    else return 0;
}
int getweight(char c)
{
    switch(c)
    {
        case '+':return 2;
        case '-':return 1;
        case '*':return 3;
        case '/':return 4;
        case '^':return 5;
        default: return -1;
    }
}
int hashigherprec(char op1,char op2)
{
    int a,b;
    a=getweight(op1);
    b=getweight(op2);
    if(a>b)
        return 1;
    else
        return 0;
}
void evalpostfix(char p[][50],int n)
{
    int i=0,j=0,res,x,op1,op2;
    printf("\n"); 
    for(i=0;i<n;i++)
    {
    	if(isoperator(p[i][j]))
    	{
    		//printf("\nanswer is:  %d\n",topperh());
    		op1=topperh();
    		poph();
    		op2=topperh();
    		poph();
    		res=perform(p[i][j],op2,op1);
    		//printf("\nanswer is:  %d\n",topperh());
    		pushh(res);
		}
		else
		{
			x=atoi(p[i]);
			pushh(x);
		}
	}
	printf("\nanswer is:  %d\n",res);
}
int perform(char p,int x,int y)
{
	switch(p)
	{
		case '+':return (x+y);
        case '-':return (x-y);
        case '*':return (x*y);
        case '/':return (x/y);
		case '^':return pow(x,y);
	}
}

