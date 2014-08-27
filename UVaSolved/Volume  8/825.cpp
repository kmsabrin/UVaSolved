#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[100][100];

void main()
{
	int T, x, y, i, j;

	char str[100], *p;

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &T );

	while ( T-- )
	{
		scanf( "%d %d\n", &y, &x );

		memset( a, 0, sizeof( a ) );

		for ( i = 1; i <= y; ++i )
		{
			gets( str );

			p = strtok( str, " " );

			j = atoi( p );

			while ( p = strtok( NULL, " " ) )
			{
				j = atoi( p );

				a[j][i] = -1;
			}
		}

		/*if ( a[1][1] != -1 )
		{
			
		}*/

		a[1][1] = 1;

		for ( i = 1; i <= y; ++i )
		{
			for ( j = 1; j <= x; ++j )
			{
				if ( a[j][i] == -1 )
				{
					continue;
				}

				if ( a[j - 1][i] != -1 )
				{
					a[j][i] += a[j - 1][i];
				}

				if ( a[j][i - 1] != -1 )
				{
					a[j][i] += a[j][i - 1];
				}
			}
		}

		printf( "%d\n", a[x][y] );

		if ( T )
		{
			scanf( "\n" );
			printf( "\n" );
		}
	}
}