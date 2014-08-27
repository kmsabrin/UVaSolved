#include <stdio.h>

int main()
{
	int i;
	int j;
	int a[11][11];
	int tc;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{
		for ( i = 1; i <= 9; i += 2 )
		{
			for ( j = 1; j <= i; j += 2 )
			{
				scanf( "%d", &a[i][j] );
			}
		}

		a[9][2] = ( a[7][1] - a[9][1] - a[9][3] ) / 2;
		a[9][4] = ( a[7][3] - a[9][3] - a[9][5] ) / 2;
		a[9][6] = ( a[7][5] - a[9][5] - a[9][7] ) / 2;
		a[9][8] = ( a[7][7] - a[9][7] - a[9][9] ) / 2;

		for ( i = 8; i >= 1; --i )
		{
			if ( i % 2 == 0 )
			{
				for ( j = 1; j <= i; ++j )
				{
					a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
				}
			}
			else
			{
				for ( j = 2; j <= i; j += 2 )
				{
					a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
				}
			}
		}

		for ( i = 1; i <= 9; ++i )
		{
			printf( "%d", a[i][1] );
			for ( j = 2; j <= i; ++j )
			{
				printf( " %d", a[i][j] );
			}
			printf( "\n" );
		}
	}

	return 0;
}
