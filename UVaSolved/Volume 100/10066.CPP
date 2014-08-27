#include <stdio.h>

#define MAX 110

int X[MAX], Y[MAX]; // input string are X and Y
int m, n; // string length of X and Y are m and n
int c[MAX][MAX]; // c is the lcs length table
int i, j; // counters

int lcs_length()
{
	for ( i = 1; i <= m; ++i ) // initialization
	{
		c[i][0] = 0;
	}
	for ( j = 0; j <= n; ++j ) // initialization
	{
		c[0][j] = 0;
	}

	for ( i = 1; i <= m; ++i )
	{
		for ( j = 1; j <= n; ++j )
		{
			if ( X[i - 1] == Y[j - 1] )
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if ( c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}

	return c[m][n];

}

int main()
{
	int tc = 1;

	while ( 1 )
	{
		scanf( "%d %d", &m, &n );

		if ( m == 0 && n == 0 )
		{
			break;
		}

		for ( i = 0; i < m; ++i )
		{
			scanf( "%d", &X[i] );
		}

		for ( j = 0; j < n; ++j )
		{
			scanf( "%d", &Y[j] );
		}

		printf( "Twin Towers #%d\n", tc++ );
		printf( "Number of Tiles : %d\n\n", lcs_length() );
	}

	return 0;
}
