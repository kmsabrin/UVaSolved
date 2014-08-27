#include <stdio.h>
#include <string.h>

#define INF 0x7fffffff

int m[11][11], s[11][11];

int p[11];

int n;

int matrix_chain_multiplication()
{

	int i, j, k, l, q;

	for ( i = 1; i <= n; ++i )
	{
		m[i][i] = 0;
	}

	for ( l = 2; l <= n; ++l )
	{
		for ( i = 1; i <= n - l + 1; ++i )
		{
			j = i + l - 1;
			m[i][j] = INF;

			for ( k = i; k <= j - 1; ++k )
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

				if ( q < m[i][j] )
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	return 0;
}


int recur( int i, int j )
{
	if ( m[i][j] == -1 )
	{
		int k, t;

		m[i][j] = INF;

		for ( k = i; k < j; ++k )
		{
			t = recur( i, k ) + recur( k + 1, j ) + p[i - 1] * p[k] * p[j];

			if ( t < m[i][j] )
			{
				m[i][j] = t;
				s[i][j] = k;
			}
		}
	}

	return m[i][j];
}


int print_mcm( int i, int j )
{
	if ( i == j )
	{
		printf( "A%d", i );
	}
	else
	{
		printf( "(" );
		print_mcm( i, s[i][j] );
		printf( " x " );
		print_mcm( s[i][j] + 1, j );
		printf( ")" );
	}

	return 0;
}

int main()
{
	int i, j, k, r, t = 0;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while ( scanf( "%d", &n ) )
	{
		if ( n == 0 )
		{
			break;
		}

		for ( i = r = 0; i < n; ++i )
		{
			scanf( "%d %d", &j, &k );

			if ( i == 0 )
			{
				p[r++] = j;
				p[r++] = k;
			}
			else
			{
				p[r++] = k;
			}
		}

		//matrix_chain_multiplication();

		{
			memset( m, -1, sizeof( m ) );

			for ( i = 1; i <= n; ++i )
			{
				m[i][i] = 0;
			}

			recur( 1, n );
		}

		printf( "Case %d: ", ++t );

		print_mcm( 1, n );

		printf( "\n" );
	}
	return 0;
}