#include<stdio.h>
int main ()
{
int a, count = 0, preflen = 0;
    while (1)
    {
        scanf("%d", &a);
        if(a==0 && preflen==3)
        {
        	count++;
		}
        if (a == 0)
        {
            switch (preflen)
            {
              case 0:
			  	preflen=0;
			  	break;
              case 1:
			  	preflen=2;
			  	break;
              case 2:
              	preflen=0;
			  	break;
              case 3:
              	preflen=2;
			  	break;
            }
        }
        else if (a == 1)
        {
            switch (preflen)
            {
              case 0:
              	preflen=1;
			  	break;
              case 1: 
              	preflen=1;
			  	break;
              case 2:
              	preflen=3;
			  	break;
              case 3:
              	preflen=1;
			  	break;
            }
        }
	else
        {
            break;
	}
	printf("\npreflen: %d\n",preflen);
    }
    printf("%d\n",count);
    return(0);
}
