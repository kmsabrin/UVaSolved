#include <stdio.h>

#define INF 0xFFFFFFF

char w[12][1001];

int a[12][1001];

int min( int a, int b, int c )
{
	int m = a;

	if ( b < m )
	{
		m = b;
	}

	if ( c < m )
	{
		m = c;
	}

	return m;
}

void main()
{
	int i, j, t, n;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &t );

	while ( t-- )
	{
		scanf( "%d", &n );

		n /= 100;

		for ( i = 0; i < n; ++i )
		{
			a[0][i] = INF;

			a[11][i] = INF;
		}

		for ( i = 1; i < 11; ++i )
		{
			a[i][0] = INF;
		}

		a[1][0] = 0;

		for ( i = 10; i >= 1; --i )
		{
			for ( j = 0; j < n; ++j )
			{
				scanf( "%d", &w[i][j] );
			}
		}

		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j <= 10; ++j )
			{
				a[j][i] = min( a[j][i - 1] - w[j][i - 1] + 30,
							   a[j - 1][i - 1] - w[j - 1][i - 1] + 20,
							   a[j + 1][i - 1] - w[j + 1][i - 1] + 60 );
			}
		}

		printf( "%d\n\n", a[1][n] );
	}
}
