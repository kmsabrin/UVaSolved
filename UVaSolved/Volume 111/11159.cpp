// graph[i][j] is true iff there is an edge from pigeon i to hole j
// matchL[m]: for each pigeon, a hole or -1
// matchR[n]: for each hole, a pigeon or -1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 128

#define N 128

bool graph[M][N];

bool seen[N];

int matchL[M], matchR[N];

int n, m;

bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) 
	{
		if( graph[u][v] )
		{
			if( seen[v] ) 
			{
				continue;
			}
			
			seen[v] = true;
			
			if( matchR[v] < 0 || bpm( matchR[v] ) )
			{
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	}
	
    return false;
}

int main()
{
	int i, j, t, kase = 0;
	
	int a[110], b[110];
	
    // Read input and populate graph[][]
    // Set m, n
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &t );
	
	while ( t-- )
	{		
		scanf( "%d", &m );
		
		for ( i = 0; i < m; ++i )
		{
			scanf( "%d", &a[i] );
		}
		
		scanf( "%d", &n );
		
		for ( j = 0; j < n; ++j )
		{
			scanf( "%d", &b[j] );
		}
		
		memset( graph, 0, sizeof( graph ) );
		
		for ( i = 0; i < m; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				if ( a[i] )
				{
					if ( ( abs( b[j] ) % abs( a[i] ) ) == 0 )
					{
						graph[i][j] = 1;
					}
				}
				else
				{
					if ( b[j] == 0 )
					{
						graph[i][j] = 1;
					}
				}
			}
		}
		
		memset( matchL, -1, sizeof( matchL ) );
		
		memset( matchR, -1, sizeof( matchR ) );
		
		int cnt = 0;
		
		for ( i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			
			if( bpm( i ) ) 
			{
				cnt++;
			}
		}
		
		// cnt contains the number of happy pigeons
		
		// matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
		
		// matchR[j] contains the pigeon in hole j or -1 if hole j is empty
		
		printf( "Case %d: %d\n", ++kase, cnt );
		
	}
	
    return 0;
}
