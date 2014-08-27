#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long a[51][51];

int s[51];

int m, n; 

int comp( const void *i, const void *j )
{
	return *( int * )i - *( int * )j;
}

int main()
{
	int i, j, k, l, c = 0;

	//freopen( "a.in", "r", stdin );
	
	while (scanf( "%d %d", &n, &m ) && n && m )
	{
		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d", &s[i] );
		}

		s[0] = -1;

		qsort( s, n + 1, sizeof( s[0] ), comp );
		
		memset( a, 0, sizeof( a ) );

		for ( i = 0; i <= n; ++i )
		{
			a[i][i] = 1;
			a[i][0] = 1;
		}

		for ( i = 1; i <= n; ++i )
		{
			if ( s[i] != s[i - 1] )
			{				
				k = 1;
				l = i - 1;

				for ( j = 1; j < i; ++j )
				{
					a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
				}
			}
			else
			{
				++k;

				for ( j = 1; j < i; ++j )
				{
					if ( j < k )
					{
						a[i][j] = a[i - 1][j];
					}
					else
					{
						a[i][j] = a[i - 1][j] + a[l][j - k];
					}
				}
			}
		}
		
		printf( "Case %d:\n" , ++c );
	
		for ( i = 0; i < m; ++i )
		{
			scanf( "%d", &j );
			printf( "%lld\n", a[n][j] );
		}
	}

	return 0;
}