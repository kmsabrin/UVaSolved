// graph[i][j] is true iff there is an edge from pigeon i to hole j
// matchL[m]: for each pigeon, a hole or -1
// matchR[n]: for each hole, a pigeon or -1

#include <string.h>
#include <stdio.h>

#define M 501
#define N 501

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
	int T;
	int i, j, k, c = 0;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &T );	

	while ( T-- )
	{
		// Read input and populate graph[][]
		// Set m, n
		
		scanf( "%d %d", &m, &n );

		memset( graph, false, sizeof( graph ) );
		
		for ( i = 0; i < m; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				scanf( "%d", &k );

				if ( k )
				{
					graph[i][j] = true;
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

		printf( "Case %d: a maximum of %d nuts and bolts can be fitted together\n", ++c, cnt );
		
	}
    return 0;
}
