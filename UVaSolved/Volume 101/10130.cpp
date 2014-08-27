/* 
ZERO ONE KNAPSACK 
DYNAMIC PROGRAMMING SOLUTION
BOTTOM UP APPROACH
*/

#include <stdio.h>

int c[1001][31];
int p[1001], w[1001];

int max( int i, int j )
{
	if ( i > j ) 
		return i;
	return j;
}

int main()
{
	int i, j, k, sum;
	int tc, n;
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &tc );
	
	while ( tc-- )
	{
		scanf( "%d", &n );
		
		for ( i = 0; i <= n; ++i )
			for ( j = 0; j <= 30; ++j )
				c[i][j] = -1;
			
			for ( i = 0; i <= n; ++i )
				c[i][0] = 0;
			
			for ( i = 0; i <= 30; ++i )
				c[0][i] = 0;
			
			for ( i = 1; i <= n; ++i )
				scanf( "%d %d", &p[i], &w[i] );
			
			for ( i = 1; i <= n; ++i )
			{
				for ( j = 1; j <= 30; ++j ) 
				{
					if ( w[i] > j )
						c[i][j] = c[i - 1][j];
					else
						c[i][j] = max( c[i - 1][j], c[i - 1][j - w[i]] + p[i] );
				}
			}
			
			scanf( "%d", &j );
			
			for ( i = sum = 0; i < j; ++i )
			{
				scanf( "%d", &k );
				sum += c[n][k];
			}
			
			printf( "%d\n", sum );
	}
	
	return 0;
}