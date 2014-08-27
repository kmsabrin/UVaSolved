

/* @JUDGE_ID: 34556CP 10013 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.116 - CRC: C0F1096A **/
/** Date: 2003-10-17 19:45:02 +0200 **/

#include<stdio.h>

int sum[1000000];

int main()
{
	long i,j,k,l,n;
	
	scanf("%ld",&n);
	
	while(n--)
	{
		scanf("%ld",&k);
		
		for(i=0;i<1000000;i++) 
			sum[i]=0; 
		
		for(i=0;i<k;i++)
		{
			scanf("%ld %ld",&l,&j);
			sum[i]=l+j;
		}
		
		for(i=k-1;i>0;i--)
			if(sum[i]>9) 
			{ 
				sum[i-1]+=1; 
				sum[i]-=10; 
			}
			
		for(i=0;i<k;i++)
			printf("%ld",sum[i]);
			
		printf("\n");					 

		if ( n )
		{
			printf( "\n" );
		}
	}
	return 0;
}

