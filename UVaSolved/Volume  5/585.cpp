#include <stdio.h>

int a[101][201];

void main()
{
	int i, j, k, m, n, u, v, kase = 0;

	char c;

	//freopen( "t.in", "r", stdin );

	//freopen( "t.out", "w", stdout );

	while ( 1 )
	{
		scanf( "%d", &n );

		if ( n == 0 )
		{
			break;
		}

		getchar();

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < i; ++j )
			{
				getchar();
			}

			for ( j = 0; j <= ( n - i - 1 ) * 2; ++j )
			{
				c = getchar();

				if ( c == '#' )
				{
					a[i][j] = 0;
				}
				else
				{
					if ( j == 0 )
					{
						a[i][j] = 1;
					}
					else
					{
						a[i][j] = a[i][j - 1] + 1;
					}
				}
			}

			getchar();
		}
				
		m = 0;

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j <= ( n - i - 1 ) * 2; ++j )
			{
				if ( j % 2 )
				{
					if ( a[i][j] == 0 )
					{
						continue;
					}

					u = i + 1; v = j - 2; k = 2;

					while ( 1 )
					{
						if ( j > ( ( n - u - 1 ) * 2 ) || v < 0 )
						{
							break;
						}

						if ( a[u][j] - a[u][v] != k || a[u][v] == 0 || a[u][j] == 0 )
						{
							break;
						}

						++u;

						v -= 2;

						k += 2;
					}

					if ( ( ( k - 2 ) / 2 ) + 1  > m )
					{
						m = ( ( k - 2 ) / 2 ) + 1;
					}					
				}
				else
				{
					if ( a[i][j] == 0 )
					{
						continue;
					}

					u = i - 1; v = j + 2; k = 2;

					while ( 1 )
					{
						if ( u < 0 )
						{
							break;
						}

						if ( a[u][v] - a[u][j] != k || a[u][v] == 0 || a[u][j] == 0 )
						{
							break;
						}

						--u;

						v += 2;

						k += 2;
					}

					if ( ( ( k - 2 ) / 2 ) + 1  > m )
					{
						m = ( ( k - 2 ) / 2 ) + 1;
					}
				}
			}
		}

		printf( "Triangle #%d\nThe largest triangle area is %d.\n\n", ++kase, m * m );
	}
}