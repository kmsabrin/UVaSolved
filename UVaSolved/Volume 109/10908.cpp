#include <stdio.h>

int valid( int x1, int y1, int x2, int y2, int m, int n )
{
	if ( x1 < 0 || x1 >= m )
		return 0;
	if ( x2 < 0 || x2 >= m )
		return 0;
	if ( y1 < 0 || y1 >= n )
		return 0;
	if ( y1 < 0 || y1 >= n )
		return 0;
	return 1;
}

int main()
{
	int i, j, k, m, n, q, f, r, c, max, tc, p, s;
	char a[1001][1001];
	char ch;

	//freopen( "in.in", "r", stdin );
	scanf( "%d", &tc );
	
	while ( tc-- )
	{

		scanf( "%d %d %d", &m, &n, &q );
		printf( "%d %d %d\n", m, n, q );

		for ( i = 0; i < m; ++i )
			scanf( "%s", &a[i] );

		//for ( i = 0; i < m; ++i )
		//	puts( a[i] );

		//printf( "??? %c %c\n", a[0][0], a[0][1] );

		for ( p = 0; p < q; ++p )
		{
			scanf( "%d %d", &r, &c );

			ch = a[r][c];

			max = 1;
			s = 3;
			for ( i = 1; ; ++i, s += 2 )
			{
				if ( valid( r - i, c - i, r + i, c + i, m, n ) == 0 )
					break;

				f = 1;
				//printf( "FOR %d \n", s );
				for ( j = r - i; j <= r + i && f; ++j )
				{
					for ( k = c - i; k <= c + i; ++k )
						if ( a[j][k] != ch )
						{
							f = 0;
							//printf( "INVALID %d %d %c\n", j, k, a[j][k] ); 
							break;
						}
				}

				if ( f )
					max = s;
			}

			printf( "%d\n", max );
		
		}
	}

	return 0;
}



