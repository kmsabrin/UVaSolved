#include <stdio.h>

#define INF 0xFFFFFFF

int c[121][16][16];

int t[121][16];

void main()
{
	int i, j, k, l, n, m;
	
	char s[15];
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%s", s ) != EOF )
	{
		scanf( "%d %d", &n, &m );
		
		for ( i = 1; i < n; ++i )
		{
			for ( j = 1; j <= m; ++j )
			{
				for ( k = 1; k <= m; ++k )
				{
					scanf( "%d", &l );
					
					c[i][j][k] = l + 2;
				}
				
				t[i][j] = INF;
			}
		}
		
		for ( i = 1; i <= m; ++i )
		{
			t[1][i] = 0;
			
			t[n][i] = INF;
		}
		
		for ( i = 1; i < n; ++i )
		{
			for ( j = 1; j <= m; ++j )
			{
				for ( k = 1; k <= m; ++k )
				{
					if ( t[i][j] + c[i][j][k] < t[i + 1][k] )
					{
						t[i + 1][k] = t[i][j] + c[i][j][k];
					}
				}
			}
		}
		
		l = t[n][1];
		
		for ( i = 2; i <= m; ++i )
		{
			if ( t[n][i] < l )
			{
				l = t[n][i];
			}
		}
		
		printf( "%s\n%d\n", s, l );
	}
}

