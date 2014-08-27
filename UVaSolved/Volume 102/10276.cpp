#include <math.h>
#include <stdio.h>
#include <string.h>

int max, N;
int p[50];

bool is_perfect( int n )
{
	int m = ( int )sqrt( n );

	if ( m * m == n )
	{
		return true;
	}

	return false;
}

void call( int i )
{
	if ( i >  max )
	{
		max = i;
	}
	
	for ( int j = 0; j < N; ++j )
	{
		if ( p[j] == 0 ) 
		{
			p[j] = i;
			call( i + 1 );
			break;
		}
		else
		{
			if ( is_perfect( p[j] + i ) == true )
			{
				p[j] = i;
				call( i + 1 );
			}
		}
	}		
}


int main()
{
	int i, j, tc;
	
	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d", &N );

		memset( p, 0, sizeof( p ) );
		
		
		for ( i = 1; ; ++i )
		{
			for ( j = 0; j < N; ++j )
			{
				if ( p[j] == 0 || is_perfect( p[j] + i ) == true )
				{
					p[j] = i;
					break;
				}
			}

			if ( j == N )
			{
				break;
			}
		}

		printf( "%d\n", i - 1 );
		

		/*
		max = 0;
		call( 1 );
		printf( "%d\n", max - 1 );
		*/
	}

	return 0;
}