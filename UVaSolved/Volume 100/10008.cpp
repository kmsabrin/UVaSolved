#include<stdio.h>
#include<ctype.h>

int main()
{
	char a[1000], b; 

	int i, j, k, max, c, d[25];

	for( i = 0; i < 26; ++i ) 
	{
		d[i]=0;
	}

	scanf("%d\n",&c); 

	while(c--)
	{
		gets(a);
		for(i=0;a[i];i++){
			if ( isalpha( a[i] ) )
			{
				b=toupper(a[i]);
				d[b-65]++;
			}
		}		
	}

	for(i=0;i<26;i++){
		max=0;
		for(j=0;j<26;j++){
			if(d[j]>max) { k=j; max=d[j]; }
		}
		if(!max) break;
		printf("%c %d\n",k+65,max);
		d[k]=0;
	}

	return 0;
}

