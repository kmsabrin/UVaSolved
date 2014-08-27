#include <stdio.h>

#define INF 0x7fffffff

int c[51];

int table[51][51];

int main()
{
	int l, m, n, i, j, k, q;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while ( 1 )
	{
		scanf( "%d", &m );

		if ( m == 0 )
		{
			break;
		}

		scanf( "%d", &n );

		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d", &c[i] );
		}

		c[0] = 0; c[n + 1] = m;

		for ( i = 0; i <= n; ++i )
		{
			table[i][i + 1] = 0;
		}

		for ( l = 2; l <= n + 1; ++l )
		{
			for ( i = 0; i <= n - l + 1; ++i )
			{
				j = i + l;

				table[i][j] = INF;

				for ( k = i + 1; k < j; ++k )
				{
					q = table[i][k] + table[k][j] + c[j] - c[i];

					if ( q < table[i][j] )
					{

						table[i][j] = q;
					}
				}

				//printf( "%d, %d = %d\n", i, j, table[i][j] );
			}
		}

		printf( "The minimum cutting is %d.\n", table[0][n + 1] );

	}

	return 0;
}


