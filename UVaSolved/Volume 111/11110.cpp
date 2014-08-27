#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[111][111];

int n;

void call( int x, int y, int k )
{
	if ( x < 1 || x > n || y < 1 || y > n )
	{
		return;
	}

	if ( a[x][y] != k )
	{
		return;
	}

	a[x][y] = -1;

	call( x + 1, y, k );

	call( x - 1, y, k );

	call( x, y + 1, k );

	call( x, y - 1, k );
}

void main()
{
	int i, j, e, x, y;

	int f[111];

	//freopen( "a.in", "r", stdin );

	char s[10000], *p;

	while ( scanf( "%d\n", &n ) && n )
	{			
		memset( a, 0, sizeof( a ) );

		memset( f, 0, sizeof( f ) );

		e = 0;

		for ( i = 1; i < n; ++i )
		{
			//j = 0;

			gets( s );

			p = strtok( s, " " );

			x = atoi( p );

			p = strtok( NULL, " " );

			y = atoi( p );

			a[x][y] = i;

			//++j;
			
			while ( p = strtok( NULL, " " ) )
			{
				x = atoi( p );

				p = strtok( NULL, " " );

				y = atoi( p );

				a[x][y] = i;

				//++j;
			}										
		
			/*if ( j != n )
			{
				e = 1;
			}*/
		}

		/*if ( e )
		{
			printf( "wrong\n" );
			continue;
		}*/

		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j <= n; ++j )
			{
				if ( a[i][j] == 0 )
				{
					a[i][j] = n;
				}
			}
		}

		for ( i = 1; i <= n && !e; ++i )
		{
			for ( j = 1; j <= n; ++j )
			{
				if ( a[i][j] != -1 )
				{
					if ( f[a[i][j]] == 1 )
					{
						e = 1;

						break;
					}

					f[a[i][j]] = 1;

					call( i, j, a[i][j] );
				}
			}
		}

		if ( e )
		{
			printf( "wrong\n" );
		}
		else
		{
			printf( "good\n" );
		}
	}
	
}

