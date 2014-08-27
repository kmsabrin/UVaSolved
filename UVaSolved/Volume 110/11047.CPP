#include <stdio.h>
#include <string.h>

#define INF 0x7ffff
#define MAXNODES 110

int nodes;
int weight[MAXNODES][MAXNODES];
int p[MAXNODES][MAXNODES];

char t[40], s[40], d[40];
char c[110][40];

void print_path2( int s, int d )
{
	if ( p[s][d] != -1 )
	{
		print_path2( s, p[s][d] );
		printf( " %s", c[d] );
	}
	else
	{
		printf( "%s", c[d] );
	}
}

void floyd_warshall()
{
	int i, j, k;

	for ( k = 0; k < nodes; ++k )
	{
		for ( i = 0; i < nodes; ++i )
		{
			for ( j = 0; j < nodes; ++j )
			{
				if ( weight[i][k] + weight[k][j] < weight[i][j] )
				{
					weight[i][j] = weight[i][k] + weight[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
}

int main()
{
	int i, j, tc, n, q, sr, ds;

	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d", &n );

		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", c[i] );
		}

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < n; ++j )
			{
				scanf( "%d", &weight[i][j] );

				if ( weight[i][j] == -1 || i == j )
				{
					p[i][j] = -1;
				}
				else
				{
					p[i][j] = i;
				}

				if ( weight[i][j] == - 1 )
				{
					weight[i][j] = INF;
				}
			}
		}

		nodes = n;

		scanf( "%d", &q );

		floyd_warshall();

		while ( q-- )
		{
			scanf( "%s %s %s", t, s, d );

			for ( i = 0; i < n; ++i )
			{
				if ( !strcmp( s, c[i] ) )
				{
					sr = i;
				}

				if ( !strcmp( d, c[i] ) )
				{
					ds = i;
				}
			}

			if ( weight[sr][ds] == INF )
			{
				printf( "Sorry Mr %s you can not go from %s to %s\n", t, s, d );
			}
			else
			{
				printf( "Mr %s to go from %s to %s, you will receive %d euros\n", t, s, d, weight[sr][ds] );
				if ( sr == ds )
				{
					printf( "Path:%s %s\n", c[sr], c[ds] );
				}
				else
				{
					printf( "Path:" );
					print_path2( sr, ds );
					printf( "\n" );
				}
			}
		}
	}

	return 0;
}
