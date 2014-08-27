// STRING MODULAS OPERATION

#include<stdio.h>

int main()
{
	int a,b,i,j,k;
	
	while(scanf("%d",&b)!=EOF)
	{
		for(i=1; ;i++)
		{
			for(j=1,k=0;j<=i;j++)
			{
				k=k*10+1;
				k=k%b;
			}
			if(!k)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}



