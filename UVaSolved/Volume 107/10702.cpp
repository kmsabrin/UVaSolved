#include <stdio.h>
#include <string.h>

int d[101][101];
int a[101][1001];

void main()
{
	int c, s, e, t, i, j, k, max;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d %d %d %d", &c, &s, &e, &t ) )
	{	
		if ( !c && !s && !e && !t )
		{
			break;
		}
				
		for ( i = 1; i <= c; ++i )
		{
			for ( j = 1; j <= c; ++j )
			{
				scanf( "%d", &d[i][j] );
			}
		}
		
		memset( a, -1, sizeof( a ) );
		
		a[s][0] = 0;
		
		for ( i = 0; i < t; ++i )
		{
			for ( j = 1; j <= c; ++j )
			{
				if ( a[j][i] != -1 )
				{
					for ( k = 1; k <= c; ++k )
					{
						if ( a[j][i] + d[j][k] > a[k][i + 1] )
						{
							a[k][i + 1] = a[j][i] + d[j][k];
						}
					}
				}
			}
		}
				
		for ( i = 1, max = 0; i <= e; ++i )
		{
			scanf( "%d", &j );
			
			if ( a[j][t] > max )
			{
				max = a[j][t];
			}
		}
		
		printf( "%d\n", max );
	}
}