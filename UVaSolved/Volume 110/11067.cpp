#include <stdio.h>
#include <string.h>

void main()
{
	int i, j, k, n, w, h;
	char a[110][110];
	unsigned long long b[110][110];

	while ( scanf( "%d %d", &w, &h ) && ( w || h ) )
	{
		scanf( "%d", &n );

		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d %d", &j, &k );
			a[j][k] = 1;
		}

		b[0][0] = 1;

		for ( i = 0; i <= w; ++i )
		{
			for ( j = 0; j <= h; ++j )
			{
				if ( !a[i][j] )
				{
					if ( i - 1 > -1 && !a[i - 1][j] )
					{
						b[i][j] += b[i - 1][j];
					}

					if ( j - 1 > -1 && !a[i][j - 1] )
					{
						b[i][j] += b[i][j - 1];
					}
				}
			}
		}

		if ( b[w][h] == 0 )
		{
			printf( "There is no path.\n" );
		}
		else if( b[w][h] == 1 )
		{
			printf( "There is one path from Little Red Riding Hood's house to her grandmother's house.\n" );
		}
		else
		{
			printf( "There are %llu paths from Little Red Riding Hood's house to her grandmother's house.\n", b[w][h] );
		}
	}
}