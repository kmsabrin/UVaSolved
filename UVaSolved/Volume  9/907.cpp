#include <stdio.h>

#define MAX( i, j ) ( ( i ) > ( j ) ) ? ( i ) : ( j )
#define MIN( i, j ) ( ( i ) < ( j ) ) ? ( i ) : ( j )

int a[301][602];

void main()
{
	int m, n, i, j, k;

	while ( scanf( "%d %d", &n, &m ) != EOF )
	{
		for ( i = 1; i <= n + 1; ++i )
		{
			scanf( "%d", &j );
			a[0][i] = a[0][i - 1] + j;
		}

		for ( i = 1; i <= m; ++i )
		{
			for ( j = 1; j <= n + 1; ++j )
			{
				if (  j <= i )
				{
					a[i][j] = a[i - 1][j];
					continue;
				}

				for ( k = j - 1, a[i][j] = 0x7FFFFFFF; a[0][j] - a[0][k] < a[i][j] && a[i - 1][k] < a[i][j] && k > 0; --k )
				{
					a[i][j] = MIN( a[i][j], MAX( a[i - 1][k], a[0][j] - a[0][k] ) );
				}
			}
		}

		printf( "%d\n", a[m][n + 1] );
	}
}



