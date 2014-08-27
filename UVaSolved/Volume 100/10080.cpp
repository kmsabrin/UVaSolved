#include <stdio.h>
#include <string.h>

#define MAX 101

struct
{
	double x, y;
} g[MAX];

struct
{
	double x, y;
} h[MAX];

bool graph[MAX][MAX];
bool seen[MAX];
int matchL[MAX], matchR[MAX];
int n, m, s, v;

bool bpm( int u )
{
    for ( int v = 0; v < m; v++ ) 
	{
		if ( graph[u][v] == true )
		{
			if ( seen[v] ) 
			{
				continue;
			}
			
			seen[v] = true;

			if ( matchR[v] < 0 || bpm( matchR[v] ) )
			{
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	}

    return false;
}

bool reachable( int i, int j )
{
	double d1 = ( s * v ) * ( s * v );
	double d2 = ( g[i].x - h[j].x ) * ( g[i].x - h[j].x ) 
		      + ( g[i].y - h[j].y ) * ( g[i].y - h[j].y ); 

	if ( d2 > d1 )
	{
		return false;
	}

	return true;
}

int main()
{
	int i, j, cnt;

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d %d %d %d", &n, &m, &s, &v ) != EOF )
	{

		for ( i = 0; i < n; ++i )
		{
			scanf( "%lf %lf", &g[i].x, &g[i].y );
		}

		for ( i = 0; i < m; ++i )
		{
			scanf( "%lf %lf", &h[i].x, &h[i].y );
		}

		memset( graph, false, sizeof( graph ) );

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < m; ++j )
			{
				graph[i][j] = reachable( i, j );
			}
		}

		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );
		cnt = 0;

		for ( i = 0; i < n; i++ )
		{
			memset( seen, 0, sizeof( seen ) );

	        if( bpm( i ) ) 
			{
				cnt++;
			}
		}

		// cnt contains the number of happy pigeons

		printf( "%d\n", n - cnt );
	}

	return 0;
}



