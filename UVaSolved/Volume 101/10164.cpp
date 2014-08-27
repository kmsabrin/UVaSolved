#include <stdio.h>
#include <string.h>

bool used[2050], cache[1030][1030];

int num[2050];

int n, N;

bool recur( int sum, int t)
{ 
	int i;
	
    if( t == n ) 
	{
		if ( sum % n == 0 )
		{
			printf( "Yes\n" );
			
			for ( i = 0; i < N; ++i )
			{
				if ( used[i] )
				{
					printf( "%d", num[i] );
					break;
				}
			}

			for ( ++i; i < N; ++i )
			{
				if ( used[i] )
				{
					printf( " %d", num[i] );				
				}
			}
			
			printf( "\n" );
			
			return true;
		}
		
		return false;
	}
	
	if( cache[sum][t] )
	{
		return false;
	}
	
	cache[sum][t]= true;
	
	for ( i = 0; i < N; ++i )
	{ 
		if ( used[i] == false )
		{
            used[i] = true;
			
            if( recur( ( sum + num[i] ) % n,t + 1 ) ) 
			{
				return true;
			}
			
			used[i] = false;
		}
	} 
	
	return false;
} 

void main()
{	
	while ( scanf( "%d", &n ) && n )
	{
		N = n * 2 - 1;
			
		for ( int i = 0; i < N; ++i )
		{
			scanf( "%d", &num[i] );			
		}

		memset( used, false, sizeof( used ) );

		memset( cache, false, sizeof( cache ) );

		if ( recur( 0, 0 ) == false )
		{
			printf( "No\n" );
		}
	}
}





