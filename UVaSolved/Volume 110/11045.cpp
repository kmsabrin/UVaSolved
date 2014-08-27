#include <stdio.h>
#include <string.h>

#define MAX 35

char graph[MAX][MAX];
char seen[MAX];
int matchL[MAX], matchR[MAX];
int n, m;

char store[][10] = { "XXL", "XL", "L", "M", "S", "XS" };

char bpm( int u )
{
    for ( int v = 0; v < n; v++ )
	{
		if ( graph[u][v] == 1 )
		{
			if ( seen[v] )
			{
				continue;
			}

			seen[v] = 1;

			if ( matchR[v] < 0 || bpm( matchR[v] ) )
			{
				matchL[u] = v;
				matchR[v] = u;
				return 1;
			}
		}
	}

    return 0;
}

void populate( int i, char s1[], char s2[] )
{
	int j, k;

	for ( j = 0; j < 6; ++j )
	{
		if ( strcmp( store[j], s1 ) == 0 )
		{
			for ( k = j; k < n; k += 6 )
			{
				graph[i][k] = 1;
			}
		}

		if ( strcmp( store[j], s2 ) == 0 )
		{
			for ( k = j; k < n; k += 6 )
			{
				graph[i][k] = 1;
			}
		}
	}
}

int main()
{
	int i, j, tc, cnt;
	char s1[10], s2[10];

//	freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d %d", &n, &m );

		memset( graph, 0, sizeof( graph ) );

		for ( i = 0; i < m; ++i )
		{
			scanf( "%s %s", s1, s2 );
			populate( i, s1, s2 );
		}

		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );

		cnt = 0;

		for ( i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );

			if ( bpm( i ) )
			{
				++cnt;
			}
		}

		// cnt contains the number of happy pigeons

		if ( cnt == m )
		{
			printf( "YES\n" );
		}
		else
		{
			printf( "NO\n" );
		}
	}

	return 0;
}



