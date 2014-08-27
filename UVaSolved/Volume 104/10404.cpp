#include <stdio.h>

char dp[1000000 + 1];

int main()
{
	int n, m, i, j;
	int stone[10];

	//freopen( "in.in", "r", stdin );

	while ( scanf( "%d %d", &n, &m ) != EOF )
	{
	
		for ( i = 0; i < m; ++i )
			scanf( "%d", &stone[i] );

		
		dp[0] = 0;
		
		for ( i = 1; i <= n; ++i )
		{
			dp[i] = 0;
			for ( j = 0; j < m; ++j )
			{
				if ( stone[j] > i )
					continue;
				if ( dp[i - stone[j]] == 0 )
				{
					dp[i] = 1;
					break;
				}			
			}
		}

		if ( dp[n] == 1 )
			printf( "Stan wins\n" );
		else
			printf( "Ollie wins\n" );
	}

	return 0;
}

