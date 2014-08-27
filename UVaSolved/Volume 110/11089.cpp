#include <stdio.h>

int fib[44];
int sum[44];

void main()
{				
	int T, n;
	int i;
	int d;
	
	fib[0] = 0;
	fib[1] = 1;
	
	sum[0] = 0;
	sum[1] = 1;
	
	for ( i = 2; i <= 43; ++i )
	{
		fib[i] = fib[i - 1] + fib[i - 2];		
		sum[i] = fib[i] + sum[i - 1];
	}
	
	scanf( "%d", &T );
	
	while ( T-- )
	{
		scanf( "%d", &n );
		
		d = -1;
		
		while ( 1 )
		{			
			i = 1;
			
			while ( n > sum[i] )
			{
				++i;
			}
			
			while ( d > i )
			{
				--d;
				printf( "0" );
			}			
			
			n = n - sum[i - 1] - 1;
			
			if ( !n )
			{
				printf( "1" );
				
				d = i - 1;
				
				while ( d )
				{
					--d;
					printf( "0" );
				}
				
				break;				
			}
			
			if ( i > 1 )
			{
				d = i - 2;
			}
			else
			{
				d = i - 1;
			}
			
			if ( i > 1 )
			{
				printf( "10" );
			}
			else
			{
				printf( "1" );
			}			
			
			if ( d < 1 )
			{
				break;
			}
		}
		
		printf( "\n" );
	}
}