#include <stdio.h>

#define INF 0xFFFFFFF

int d[11][11][31];

int a[11][1002];

int D[11][11];

int kase;

void main()
{
	int m, n, t, i, j, k;
		
	while ( scanf( "%d %d", &n, &t ) )
	{	
		if ( !n && !t )
		{
			break;
		}
				
		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j <= n; ++j )
			{			
				if ( i == j )
				{
					continue;
				}
				
				scanf( "%d", &m );
				
				D[i][j] = m;
				
				for ( k = 1; k <= m; ++k )
				{
					scanf( "%d", &d[i][j][k] );
				}				
			}
		}
		
		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j <= t + 1; ++j )
			{
				a[i][j] = INF;
			}
		}
		
		a[1][1] = 0;
		
		for ( i = 1; i <= t; ++i )
		{						
			for ( j = 1; j <= n; ++j )
			{
				if ( a[j][i] != INF )
				{					
					for ( k = 1; k <= n; ++k )
					{
						if ( k == j )
						{
							continue;
						}

						m = i % D[j][k];
						
						if ( m == 0 )
						{
							m = D[j][k];
						}
												
						if ( d[j][k][m] && a[j][i] + d[j][k][m] < a[k][i + 1] )
						{
							a[k][i + 1] = a[j][i] + d[j][k][m];
						}
					}
				}
			}
		}
		
		printf( "Scenario #%d\n", ++kase );
		
		if ( a[n][t + 1] == INF )
		{
			printf( "No flight possible.\n\n" );
		}
		else
		{
			printf( "The best flight costs %d.\n\n", a[n][t + 1] );
		}
	}
}