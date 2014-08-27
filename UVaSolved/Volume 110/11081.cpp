#include <stdio.h>
#include <string.h>

char a[61], b[61], c[61];

int d[2][61][61][61];

int call( int t, int x, int y, int z )
{
	int s;
		
	if ( d[t][x][y][z] != -1 )
	{
		return d[t][x][y][z];
	}
	
	if ( !t )
	{
		s = call( 0, x + 1, y, z );
				
		if ( a[x] == c[z] )
		{
			s += call( 0, x + 1, y, z + 1 ) + call( 1, x + 1, y, z + 1 );
		}
	}
	else
	{
		s = call( 1, x, y + 1, z );
				
		if ( b[y] == c[z] )
		{
			s += call( 0, x, y + 1, z + 1 ) + call( 1, x, y + 1, z + 1 );
		}
	}
	
	return d[t][x][y][z] = s % 10007;		
}

void main()
{
	int i, j, k, x, y, z, T;

	/*freopen( "a.in", "r", stdin );*/
	
	scanf( "%d", &T );
	
	while ( T-- )
	{
		scanf( "%s %s %s", a, b, c );
		
		x = strlen( a );

		y = strlen( b );

		z = strlen( c );

		for ( i = 0; i <= x; ++i )
		{
			for ( j = 0; j <= y; ++j )
			{
				for ( k = 0; k < z; ++k )
				{
					d[0][i][j][k] = d[1][i][j][k] = -1;
				}
			}
		}
		
		for ( i = 0; i <= x; ++i )
		{
			for ( j = 0; j <= y; ++j )
			{
				d[0][i][j][z] = d[1][i][j][z] = 1;
			}
		}
						
		for ( j = 0; j <= y; ++j )
		{
			for ( k = 0; k < z; ++k )
			{
				d[0][x][j][k] = 0;
				/*d[1][x][j][k] = -1;*/
			}
		}				
		
		for ( i = 0; i <= x; ++i )
		{
			for ( k = 0; k < z; ++k )
			{
				d[1][i][y][k] = 0;
				/*d[0][i][y][k] = -1;*/
			}
		}
		
		printf( "%d\n", ( ( call( 0, 0, 0, 0 ) + call( 1, 0, 0, 0 ) ) / 2 ) % 10007 );
	}
}