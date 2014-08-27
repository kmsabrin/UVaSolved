#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[35];

int y[35];

int a[35][35];

int used[35];

int cnt;

int n;

int T;

int d;

int min;

int cost;

int val( int s )
{
	return abs( x[s] - x[0] ) + abs( y[s] - y[0] );
}

int call( int s )
{	
	int i, j;

	if ( cost + val( s ) >= min )
	{
		return 0;
	}
	
	if ( cnt == n )
	{
		if ( cost + val( s ) < min )
		{
			min = cost + val( s );
		}
		
		return 0;
	}
	
	for ( i = 1; i <= n; ++i )
	{
		if ( !used[i] )
		{
			/*for ( j = 1; j <= n; ++j )
			{
				if ( j == i )
				{
					continue;
				}

				if ( !used[j] && a[s][j] + a[j][i] <= a[s][i] )
				{
					break;
				}
			}

			if ( j <= n )
			{
				continue;
			}*/

			cost += a[s][i];
			
			used[i] = 1;
			
			++cnt;
			
			call( i );
			
			--cnt;
			
			used[i] = 0;
			
			cost -= a[s][i];
		}
	}

	return 0;
}

int main()
{
	int i, j, t;
		
	//freopen( "b.in", "r", stdin );

	scanf( "%d", &t );
	
	while ( t-- )
	{		
		scanf( "%d %d", &i, &j );

		scanf( "%d %d", &x[0], &y[0] );

		scanf( "%d", &n );
			
		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d %d", &x[i], &y[i] );				
		}
				
		for ( i = 0; i <= n; ++i )
		{
			for ( j = i + 1; j <= n; ++j )
			{
				a[i][j] = a[j][i] = abs( x[i] - x[j] ) + abs( y[i] - y[j] );
			}			
		}
		
		memset( used, 0, sizeof( used ) );
		
		cnt = 0;
		
		cost = 0;
						
		min = 0xFFFFFF;

		used[0] = 1;
		
		call( 0 );
		
		printf( "The shortest path has length %d\n", min );
	}
	
	return 0;
}