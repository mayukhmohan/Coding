#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct contact
{
	char name[20],email[30],telephone[20];
	struct address	
	{
		char street[20],city[20],country[20];
		char zipcode[10];	
	};
	struct address p;
};
struct node
{
	struct contact *ptr;
	struct node *next;
};
struct node *head=NULL;
void del(char *pt);
void ins(struct contact *);
int getcount(void);
void modify(char *);
void export(char *);
void getcontacts(void);
void add(void);
void load(char *);
void get(char *pt);
void search(char *pt);
void choice(void);
void main()
{
	choice();
}
void choice(void)
{
	int x;
	while(1)
	{
		char name1[20];
		system("cls");
		printf("1.To insert\n2.To delete\n3.Show details\n4.To load address book\n5.To count\n6.To getcontact\n7.To modify\n8.To export address book\n9.To Search\n10.To exit\n");
		printf("enter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				add();
				break;
			case 2:
				printf("enter a name to delete: ");
				scanf("%s",&name1);
				del(name1);
				break;		
			case 3:
				printf("enter a name: ");
				scanf("%s",&name1);
				get(name1);
				break;
			case 4:
				printf("\nenter your filename:");
				scanf("%s",&name1);
				load(name1);
				break;
			case 5:
				getcount();
				break;
			case 6:
				getcontacts();
				break;
			case 7:
				printf("enter your name: ");
				scanf("%s",&name1);
				modify(name1);
				break;
			case 8:
				printf("\nenter your filename:");
				scanf("%s",&name1);
				export(name1);
				break;
			case 9:
				printf("\nenter name to search: ");
				scanf("%s",&name1);
				search(name1);
				break;
			case 10:
				exit(0);
		}
	}
}
void add(void)
{
	struct contact *c;
	c=(struct contact *)malloc(sizeof(struct contact));
	printf("\nenter your name:");
	scanf("%s",&(c->name));
	/*printf("\nenter your email:");
	scanf("%s",&(c->email));
	printf("\nenter your telephone number:");
	scanf("%s",&(c->telephone));
	printf("\nenter your address:\n\nstreet:");
	scanf("%s",&(c->p.street));
	printf("\ncity:");
	scanf("%s",&(c->p.city));
	printf("\ncountry:");
	scanf("%s",&(c->p.country));
	printf("\nzipcode:");
	scanf("%s",&(c->p.zipcode));*/
	ins(c);
}
void modify(char *p)
{
	char n1[20],n2[20];
	struct node *temp=head;
	while(strcmp(p,temp->ptr->name) && temp->next!=NULL)
	{
		temp=temp->next;
	}
	printf("field you want to modify....: ");
	scanf("%s",&n1);
	printf("what it should be? ");
	scanf("%s",&n2);
	   	if(!strcmp(n1,"email")){
	   		strcpy(temp->ptr->email,n2);
			   	}
	   	if(!strcmp(n1,"telephone")){
	   		strcpy(temp->ptr->telephone,n2);
	   	}
	   	if(!strcmp(n1,"street")){
	   		strcpy(temp->ptr->p.street,n2);
		}
		if(!strcmp(n1,"city")){
			strcpy(temp->ptr->p.city,n2);
		}
		if(!strcmp(n1,"country")){
			strcpy(temp->ptr->p.country,n2);
		}
		if(!strcmp(n1,"zipcode")){
			strcpy(temp->ptr->p.zipcode,n2);	
        }
        //getch();
        int x;
        printf("press 1:");
        scanf("%d",&x);
        if(x==1)
        {
        	return;
		}
}
void ins(struct contact *c)
{
    struct node *temp1,*temp2;
    temp2=head;
    temp1=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        temp1->ptr=c;
        temp1->next=NULL;
        head=temp1;
    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp1->ptr=c;
        temp2->next=temp1;
        temp1->next=NULL;
    }
}
void get(char *pt)
{
	struct node *temp=head;
	while(strcmp(pt,temp->ptr->name) && temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		return;
	}
	printf("Result:\n\n");
	printf("Name:%s, Email:%s, Telephone:%s, Address:\nStreet:%s\nCity:%s\nCountry:%s\nZipCode:%s",temp->ptr->name,
	temp->ptr->email,temp->ptr->telephone,temp->ptr->p.street,temp->ptr->p.city,temp->ptr->p.country,temp->ptr->p.zipcode);
	//getch();
	int x;
        printf("press 1:");
        scanf("%d",&x);
        if(x==1)
        {
        	return;
		}
}
void del(char *pt)
{
    struct node *temp1=head,*temp2=NULL;
    while(strcmp(pt,temp1->ptr->name) && temp1->next!=NULL)
    {
    	temp2=temp1;
    	temp1=temp1->next;
	}
	if(temp1==head)
	{
		head=temp1->next;
		free(temp1);
		temp1=NULL;
	}
	else
	{
		temp2->next=temp1->next;
		free(temp1);
		temp1=NULL;
	}
}
int getcount(void)
{
	struct node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("\ncounter:%d\n",c);
	int x;
        printf("press 1:");
        scanf("%d",&x);
        if(x==1)
        {
        	return c;
		}
	//getch();
}
void export(char *pt)
{
	FILE *fp;
	struct node *temp=head;
	fp=fopen(pt,"w");
	while(temp!=NULL)
	{
		fprintf(fp,"%s %s %s %s %s %s %s\n",temp->ptr->name,temp->ptr->email,temp->ptr->telephone,
		temp->ptr->p.street,temp->ptr->p.city,temp->ptr->p.country,temp->ptr->p.zipcode);
		temp=temp->next;
	}
	fclose(fp);
}
void load(char *pt)
{
	FILE *fp;
	char ch;
	fp=fopen(pt,"r");
	while((ch=getc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	//getch();
	int x;
        printf("press 1:");
        scanf("%d",&x);
        if(x==1)
        {
        	return;
		}
}
void getcontacts(void)
{
	int i=0,j,f=1,n=getcount();
	char c[n][20],ch[20];
	struct node *temp=head;
	while(temp!=NULL)
	{
		strcpy(c[i],temp->ptr->name);
		i++;
		temp=temp->next;
	}
	for(i=0;i<n-1 && f;i++)
	{
		f=0;
		for(j=0;j<n-1-i; j++)
		{
			if(strcmp(c[j],c[j+1])>0)
			{
				strcpy(ch,c[j]);
				strcpy(c[j],c[j+1]);
				strcpy(c[j+1],ch);
				f=1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		get(c[i]);	
	}
	//getch();
	int x;
        printf("press 1:");
        scanf("%d",&x);
        if(x==1)
        {
        	return;
		}
}
void search(char *pt)
{
	char arr[50][50],ch[50],nam[100];
	int pos=0,f=0,i=0,j;
	struct node *temp=head;
	while(temp!=NULL)
	{
		i=0;
		f=0;
		while(temp->ptr->name[i]!='\0')
		{
			//printf("\n%s1\n",temp->ptr->name);
			if(temp->ptr->name[i]==pt[i])
			{
				f++;
				i++;
			}
			else
			{
				break;
			}
		}
		if(f==strlen(pt))
		{
			strcpy(nam,temp->ptr->name);
			strcpy(arr[pos],nam);
			pos++;
		}
		temp=temp->next;
	}
	for(i=0;i<pos;i++)
	{
		printf("\n%s2\n",arr[i]);
	}
	f=1;
	for(i=0;i<pos-1 && f;i++)
	{
		f=0;
		for(j=0;j<pos-1-i; j++)
		{
			if(strcmp(arr[j],arr[j+1])>0)
			{
				strcpy(ch,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],ch);
				f=1;
			}
		}
	}
	for(i=0;i<pos;i++)
	{
		printf("\n%s\n",arr[i]);
	}
	getch();
}




