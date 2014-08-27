#include <stdio.h>
#include <string.h>

#define SIZE 215

int l[SIZE];

int loc[SIZE];

int ct[SIZE];

int p[SIZE][10000 + 1];

int call( int a, int b, int c )
{		
	int x;		
	
	if ( l[a] <= b )
	{
		if ( p[a + 1][b - l[a]] == -1 )
		{
			p[a + 1][b - l[a]] = call( a + 1, b - l[a], c );
		}
				
		x = 1 + p[a + 1][b - l[a]];
	}	
	else
	{
		x = 0;
	}
	
	if ( x > ct[a] )
	{
		ct[a] = x;
		loc[a] = 1;				
	}

	if ( l[a] <= c )
	{
		if ( p[a + 1][c - l[a]] == -1 )
		{
			p[a + 1][c - l[a]] = call( a + 1, b, c - l[a] );
		}
				
		x = 1 + p[a + 1][c - l[a]];
	}
	else
	{
		x = 0;
	}			
	
	if ( x > ct[a] )
	{
		ct[a] = x;
		loc[a] = 2;				
	}

	return ct[a];	
}

void main()
{
	int i, j, k, a, b, c, r, len, n, T;
		
	scanf( "%d", &T );
	
	while ( T-- )
	{		
		scanf( "%d", &len );
		
		i = 0;
		
		while ( scanf( "%d", &n ) && n )
		{
			l[i++] = n;
		}
		
		l[i] = 0xFFFFFFF;
		
		a = 0, b = c = len * 100;
		
		for ( j = 0; j <= i; ++j )
		{
			for ( k = 0; k <= b; ++k )
			{
				p[j][k] = -1;
			}
		}
		
		if ( l[a] > b )
		{		
			printf( "0\n" );		
		}
		else
		{
			memset( ct, 0, sizeof( ct ) );
			
			r = 1 + call( a + 1, b - l[a], c );

			printf( "%d\n", r );

			loc[0] = 1;

			for ( i = 0; i < r; ++i )
			{
				if ( loc[i] == 1 )
				{
					printf( "port\n" );
				}
				else
				{
					printf( "starboard\n" );
				}
			}			
		}

		if ( T )
		{
			printf( "\n" );
		}
	}
}

