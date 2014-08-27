#include <stdio.h>

int t[221][11][221];

void fill_table()
{
	int i, j, k, l;

	for ( i = 1; i <= 220; ++i )
	{
		t[i][1][i] = 1;		
	}

	for ( i = 2; i <= 220; ++i )
	{
		for ( j = 1; j <= i / 2; ++j )
		{
			t[i][2][j] = 1;
		}
	}

	for ( i = 2; i <= 220; ++i )
	{
		for ( j = 3; j <= i && j <= 10; ++j )
		{
			for ( k = 1; k <= i / j; ++k )
			{
				for ( l = k; l <= ( i - k ) / ( j - 1 ); ++l )
				{
					t[i][j][k] += t[i - k][j - 1][l];
				}
			}			
		}
	}
}

void call( int m, int n, int k )
{
	if ( n == 1 )
	{
		printf( "%d\n", m );

		return;
	}

	int i, j, r, s;	

	s = 0;

	for ( i = 1; ; ++i )
	{
		if ( s + t[m][n][i] >= k )
		{
			break;
		}

		s += t[m][n][i];
	}

	k -= s;

	printf( "%d\n", i );

	r = 0;

	for ( j = 1; j < i; ++j )
	{
		r += t[m - i][n - 1][j];
	}

	call( m - i, n - 1, r + k );
}
		
void main()
{
	fill_table();

	int n, m, k, T;
	
	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d %d %d", &n, &m, &k );

		call( n, m, k );
	}
}
