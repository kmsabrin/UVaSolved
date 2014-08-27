#include <stdio.h>

int a[101][101];

int main()
{
	int i, j, k, n, cnt;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) != EOF )
	{		
		
		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				scanf( "%d", &a[i][j] );
			}
		}

		cnt = 0;

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				for ( k = 0; k < n; ++k )
				{
					if ( ( i < j && j < k ) || ( i > j && j > k ) )
					{
						if ( a[i][j] && a[j][k] && a[k][i] )
						{
							printf( "%d %d %d\n", i + 1, j + 1, k + 1 );
							++cnt ;
						}
					}
				}
			}
		}

		printf( "total:%d\n\n", cnt );
	}

	return 0;
}



