#include <stdio.h>
#include <string.h>

#define INF 0xFFFFFFF

int a[501][501];

void main()
{
	int i, j, k, l, n, t, m, c = 0, T;
		
	n = 500;
	
	for ( i = 1; i <= n; ++i )
	{				
		a[i][i] = i;
	}
	
	for ( l = 2; l <= n; ++l )
	{
		for ( i = 1; i <= n - l + 1; ++i )
		{
			j = i + l - 1;
			
			m = INF;

			for ( k = i; k < j; ++k )
			{
				t = k;

				if ( k - i == 1 )
				{
					t += k;
				}
				else if ( k - i > 1 )
				{
					t += a[i][k - 1] + ( k - i ) * k;
				}

				if ( j - k == 1 )
				{
					t += k;
				}
				else if ( j - k > 1 )
				{
					t += a[k + 1][j] + ( j - k ) * k;
				}

				if ( t < m )
				{
					m = t;
				}
			}

			a[i][j] = m;
		}
	}

	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d %d", &n, &k );

		printf( "Case %d: %d\n", ++c, a[1 + k][n + k] );
	}
	
}
