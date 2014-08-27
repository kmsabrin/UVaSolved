#include <stdio.h>

int count;
int m, n;

char a[30][30];
char c, d;

void fill( int x, int y )
{
	if ( a[x][y] == d )
	{
		return;
	}
	
	if ( x < 0 || x >= m )
	{
		return;
	}
	
	++count;
	
	a[x][y] = d;
	
	if ( y == 0 )
	{
		fill( x, n - 1 );
	}
	else
	{
		fill( x, y - 1 );
	}
	
	if ( y == n - 1 )
	{
		fill( x, 0 );
	}
	else
	{
		fill( x, y + 1 );
	}
	
	fill( x - 1, y );
	fill( x + 1, y );
}

void main()
{
	int x, y;
	int i, j;
	int max;
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d %d", &m, &n ) != EOF )
	{		
		for ( i = 0; i < m; ++i )
		{
			scanf( "%s", a[i] );
		}
		
		scanf( "%d %d", &x, &y );

		c = a[x][y];

		int f = 1;

		for ( i = 0; i < m; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				if ( a[i][j] != c )
				{
					d = a[i][j];
					f = 0;
					break;
				}
			}

			if ( !f )
			{
				break;
			}
		}
		
		fill( x, y );
				
		max = 0;
		
		for ( i = 0; i < m; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				if ( a[i][j] == c )
				{
					count = 0;

					fill( i, j );
												
					if ( count > max )
					{
						max = count;
					}
				}
			}
		}		
		
		printf( "%d\n", max );		
	}
}