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
	return abs( x[s] - d + 1 ) + abs( y[s] - d + 1 );
}

int call( int s )
{	
	int i, j;

	if ( cost + val( s ) >= min )
	{
		return 0;
	}
	
	if ( cnt == T )
	{
		if ( cost + val( s ) < min )
		{
			min = cost + val( s );
		}
		
		return 0;
	}
	
	for ( i = 0; i <= n; ++i )
	{
		if ( s != i && !used[i] )
		{
			for ( j = 0; j <= n; ++j )
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
			}

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
	int i, j, k = 0;
		
	//freopen( "b.in", "r", stdin );
	
	while ( scanf( "%d %d %d", &d, &n, &T ) )
	{		
		if ( !d && !n && !T )
		{
			break;
		}

		x[0] = 0;
		y[0] = 0;
			
		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d %d", &x[i], &y[i] );				
		}
				
		for ( i = 0; i <= n; ++i )
		{
			for ( j = i; j <= n; ++j )
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
		
		printf( "Case %d: %d\n", ++k, min );
	}
	
	return 0;
}