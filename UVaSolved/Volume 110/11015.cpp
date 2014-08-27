#include <stdio.h>

#define INF 0x7fffffff

int a[100][100];

int main()
{
	int i, j, k, t, tc = 0;
	int m, n, d, f, min;
	char name[100][20];

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{

		scanf( "%d %d", &n, &m );

		if ( n == 0 )
		{
			break;
		}

		for ( i = 1; i <= n; ++i )
		{
			scanf( "%s", &name[i] );
		}

		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j <= n; ++j )
			{
				if ( i == j )
				{
					a[i][j] = 0;
				}
				else
				{
					a[i][j] = INF;
				}
			}
		}

		for ( i = 0; i < m; ++i )
		{
			scanf( "%d %d %d", &j, &k, &d );
			a[j][k] = a[k][j] = d;
		}

		for ( k = 1; k <= n; ++k )
		{
			for ( i = 1; i <= n; ++i )
			{
				for ( j = 1; j <= n; ++j )
				{
					if ( a[i][k] + a[k][j] < a[i][j] )
					{
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}

		
		min = 0x7fffffff; 

		for ( i = 1; i <= n; ++i )
		{
						
			for ( k = 0, j = 1; j <= n; ++j )
			{		
				k += a[i][j];
			}

			if ( k < min )
			{
				min = k;
				t = i;					
			}			
		}

		printf( "Case #%d : %s\n", ++tc, name[t] );		

	}

	return 0;
}
