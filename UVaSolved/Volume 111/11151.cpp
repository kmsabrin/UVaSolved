#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[1002][1002];

char s[1002];

int min( int a, int b, int c )
{
	int d = a;

	if ( b < d )
	{
		d = b;
	}

	if ( c < d )
	{
		d = c;
	}

	return d;
}

void main()
{
	int i, j, l, n, t, T;
						
	//freopen( "a.in", "r", stdin );
	
	//scanf( "%d\n", &T );

	T = atoi( gets( s ) );

	s[0] = '?';

	for ( t = 1; t <= T; ++t )
	{		
		gets( s + 1 );

		//puts( s );

		n = strlen( s ) - 1;		
				
		for ( l = 2; l <= n; ++l )
		{
			for ( i = 1; i <= n - l + 1; ++i )
			{
				j = i + l - 1;
				
				if ( s[i] == s[j] )
				{
					a[i][j] = a[i + 1][j - 1];					
				}
				else
				{
					//a[i][j] = min( a[i + 1][j - 1], a[i][j - 1], a[i + 1][j] ) + 1;															
					a[i][j] = min( 11111, a[i][j - 1], a[i + 1][j] ) + 1;															
				}				
			}
		}
		
		//printf( "Case %d: %d\n", t, a[1][n] ) ;				

		printf( "%d\n", n - a[1][n] );
	}
}