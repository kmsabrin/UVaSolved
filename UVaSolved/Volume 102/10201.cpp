#include <stdio.h>
#include <stdlib.h>

#define INF 0xFFFFFFF

#define S 101

void main()
{
	char str[40];
	
	int fd;
	
	int i, j, k, l, m;
	
	int n, T;
	
	int d[S], p[S];
	
	int c[S + 2][203];
	
	//freopen( "a.in", "r", stdin );
	
	//freopen( "a.out", "w", stdout );
	
	T = atoi( gets( str ) );

	gets( str );
	
	while ( T-- )
	{		
		gets( str );

		fd = atoi( str );
				
		d[0] = p[0] = 0;
		
		i = 1;
		
		while ( gets( str ) && *str )
		{
			sscanf( str, "%d %d", &d[i], &p[i] );
			
			++i;
		}
		
		n = i - 1;

		for ( i = 0; i <= n; ++i )
		{
			if ( d[i] == fd )
			{
				n = i;
				break;
			}
			else if ( d[i] > fd )
			{
				n = i - 1;
				break;
			}
		}
		
		for ( i = 0; i <= 200; ++i )
		{
			c[0][i] = INF;			
		}
		
		c[0][100] = 0;
		
		for ( i = 1; i <= n; ++i )
		{
			for ( j = 0; j <= 200; ++j )
			{
				c[i][j] = INF;
				
				for ( k = i - 1; k >= 0; --k )
				{
					m = d[i] - d[k];
					
					if ( m > 200 )
					{
						break;
					}
					
					for ( l = m; l <= 200 && l <= ( m + j ); ++l )
					{
						if ( ( c[k][l] + ( j - l + m ) * p[i] ) < c[i][j] )
						{
							c[i][j] = c[k][l] + ( j - l + m ) * p[i];
						}
					}
				}
			}
		}
				
		int min = INF;
		
		for ( i = n; i >= 0; --i )
		{
			if ( fd - d[i] > 100 )
			{
				break;
			}
			
			for ( j = fd - d[i] + 100; j <= 200; ++j )
			{
				if ( c[i][j] < min )
				{
					min = c[i][j];
				}
			}
		}
		
		if ( min == INF )
		{
			printf( "Impossible\n" );
		}
		else
		{
			printf( "%d\n", min );
		}
		
		if ( T )
		{
			printf( "\n" );
		}
		
	}
}