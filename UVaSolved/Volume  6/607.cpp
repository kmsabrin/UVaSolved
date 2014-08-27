#include <stdio.h>

#define INF 0x7fffffff

int d[1010][1010];
int t[1010];
int n, L, C;

int main()
{
	int i, j, k;
	int x, y;
	int tc = 1;

	while ( 1 )
	{
		scanf( "%d", &n );

		if ( n == 0 )
		{
			break;
		}

		scanf( "%d %d", &L, &C );

		for ( i = 1; i <= n; ++i )
		{
			scanf( " %d", &t[i] );
		}

		for ( i = 0; i <= n; ++i )
		{
			for ( j = 0; j <= n; ++j )
			{
				d[i][j] = INF;
			}
		}

		d[0][0] = 0;

		for ( i = 1; i <= n; ++i )
		{
			for ( j = i; j <= n; ++j )
			{
				if ( d[i - 1][j - 1] == INF )
				{
					break;
				}

				x = 0;

				for ( k = j; k <= n; ++k )
				{
					x += t[k];

					if ( x > L )
					{
						break;
					}

					if ( L - x == 0 )
					{
						y = d[i - 1][j - 1];
					}
					else if ( L - x <= 10 )
					{
						y = d[i - 1][j - 1] - C;
					}
					else
					{
						y = d[i - 1][j - 1] + ( L - x - 10 ) * ( L - x - 10 );
					}

					if ( y < d[i][k] )
					{
						d[i][k] = y;
					}
				}
			}

			if ( d[i][n] != INF )
			{
				break;
			}
		}

		if ( tc > 1 )
		{
			printf( "\n" );
		}
		printf( "Case %d:\n", tc++ );
		printf( "Minimum number of lectures: %d\n", i );
		printf( "Total dissatisfaction index: %d\n", d[i][n] );
	}

	return 0;
}
