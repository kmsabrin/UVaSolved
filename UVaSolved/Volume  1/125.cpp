#include <stdio.h>
#include <string.h>

#define MAXNODES 31

int nodes;
int edges;
int flg;
bool used[MAXNODES];
int path[MAXNODES][MAXNODES];
bool edge[MAXNODES][MAXNODES];

void init_graph()
{
	memset( used, false, sizeof( used ) );
	memset( path, 0, sizeof( path ) );
	memset( edge, false, sizeof( edge ) );
}

void dfs( int s, int v )
{
	int i;

	if ( flg && used[v] == true )
	{
		++path[s][v];
		return;
	}
	else
	{
		if ( flg ) // for initial call
		{
			++path[s][v];
			used[v] = true;
		}

		flg = 1;

		for ( i = 0; i <= nodes; ++i)
		{
			if ( edge[v][i] )
			{
				dfs( s, i );
			}
		}

		used[v] = false;
	}
}

/*
void floyd_warshall()
{
	int i, j, k;

	for ( i = 0; i <= nodes; ++i )
	{
		for ( j = 0; j <= nodes; ++j )
		{
			for ( k = 0; k <= nodes; ++k )
			{
				if ( path[i][k] && path[k][j] )
				{
					++path[i][j];
				}
			}
		}
	}
}
*/

void print_adj_matrix()
{
	int i, j;

	for ( i = 0; i <= nodes; ++i )
	{
		for ( j = 0; j < nodes; ++j )
		{
			printf( "%d ", path[i][j] );
		}
		printf( "%d\n", path[i][j] );
	}
}

int main()
{
	int i, j, k, c = 0;

	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );

	while ( scanf( "%d", &edges ) != EOF )
	{

		init_graph();

		nodes = -1;

		for ( i = 0; i < edges; ++i )
		{
			scanf( "%d %d", &j, &k );
			edge[j][k] = true;
			path[j][k] = 1;

			if ( j > nodes )
			{
				nodes = j;
			}

			if ( k > nodes )
			{
				nodes = k;
			}
		}



		for ( i = 0; i <= nodes; ++i )
		{
			flg = 0;
			dfs( i, i );
		}


		//floyd_warshall(); // does not work
		//print_adj_matrix();

		for ( i = 0; i <= nodes; ++i )
		{
			if ( path[i][i] )
			{
				for ( j = 0; j <= nodes; ++j )
				{
					if ( path[i][j] )
					{
						path[i][j] = -1;
					}
				}
			}
			else
			{
				for ( j = 0; j <= nodes; ++j )
				{
					if ( path[i][j] && path[j][j] )
					{
						for ( k = 0; k <= nodes; ++k )
						{
							if ( path[j][k] )
							{
								path[i][k] = -1;
							}
						}
					}
				}
			}
		}

		printf( "matrix for city %d\n", c++ );
		print_adj_matrix();
	}


	return 0;
}


