#include <stdio.h>

int c[101][10201];
bool t[101][10201];
int p[1001], w[1001];
int s;

void items_taken( int n, int m )
{
	if ( n == 0 || m == 0 )
	{
		return;
	}	

	if ( t[n][m] == true )
	{
		s += w[n];
		items_taken( n - 1, m - w[n] );
	}
	else
	{
		items_taken( n - 1, m );
	}
}

int main()
{
	int i, j;
	int m, n;
	
	//freopen( "a.in", "r", stdin );
	
	for ( i = 0; i <= 101; ++i )
	{
		c[i][0] = 0;
	}
	
	for ( i = 0; i <= 10201; ++i )
	{
		c[0][i] = 0;
	}
	
	while ( scanf( "%d %d", &m, &n ) != EOF )
	{													
		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d %d", &w[i], &p[i] );
		}
		
		m += 200;
		
		for ( i = 1; i <= n; ++i )			
		{
			for ( j = 1; j <= m; ++j ) 
			{
				if ( w[i] > j )
				{
					c[i][j] = c[i - 1][j];
					t[i][j] = false;
				}
				else
				{
					if ( c[i - 1][j] < c[i - 1][j - w[i]] + p[i] )
					{
						c[i][j] = c[i - 1][j - w[i]] + p[i];
						t[i][j] = true;
					}
					else
					{
						c[i][j] = c[i - 1][j];
						t[i][j] = false;
					}
				}
			}
		}
				
		s = 0;

		items_taken( n, m );

		if ( s > 2000 )
		{
			printf( "%d\n", c[n][m] );
		}
		else
		{
			printf( "%d\n", c[n][m - 200] );
		}
	}
	
	return 0;
}