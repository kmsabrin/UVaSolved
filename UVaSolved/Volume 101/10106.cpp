// STRING MULTIPLICATION

#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000],b[1000];
	int c[3000];
	int t,n,m,i,j,k,count,carry;
	for(i=2999; i>=0; i--)
		c[i]=0;
	while(gets(a))
	{
		gets(b);
		n=strlen(a)-1;
		m=strlen(b)-1;
		if(a[0]=='0' || b[0]=='0')
		{
			printf("0\n");
			continue;
		}
		else
		{
			count = carry = 0;
			for(i=m; i>=0; i--)
			{
				k=count;
				for(j=n; j>=0; j--)
				{
					t = (a[j]-48)*(b[i]-48) + c[k] + carry;
					c[k] = t%10;
					if(t>9)
						carry = t/10;
					else
						carry = 0;
					/* printf("%d %d %d %d %d %d\n",k,t,c[k],a[j]-48,b[i]-48,carry); */
					/* check point */
					k++;
				}
				while(carry)
				{
					c[k] = carry%10;
					carry /= 10;
					k++;
				}
				count++;
			}
			
			for(i=k-1; i>-1; i--)
				printf("%d",c[i]);
			printf("\n");
		}
		for(i=2999; i>=0; i--)
			c[i]=0;
	}
	return 0;
}
