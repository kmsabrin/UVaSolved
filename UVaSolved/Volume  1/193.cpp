#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAXNODES 100

struct adj_list
{
	vector <int> l;
}	adj[MAXNODES + 1];

int color[MAXNODES + 1], used[MAXNODES + 1], found[MAXNODES + 1];

int nNodes;

int max_black;

void call()
{
	int i, j, k, f;

	for ( i = 1; i <= nNodes; ++i )
	{
		if ( !used[i] )
		{
			for ( j = f = 0; j < adj[i].l.size(); ++j )
			{
				k = adj[i].l[j];

				if ( used[k] && color[k] == 'B' )
				{
					f = 1;
					break;
				}
			}

			if ( f ) // node has a black neighbor
			{
				used[i] = 1;

				color[i] = 'W';
				call();

				used[i] = 0;
			}
			else
			{
				used[i] = 1;

				color[i] = 'W';
				call();

				color[i] = 'B';
				call();

				used[i] = 0;
			}

			break;
		}
	}

	if ( i > nNodes )
	{
		for ( j = 1, k = 0; j <= nNodes; ++j )
		{
			if ( color[j] == 'B' )
			{
				++k;
			}
		}

		if ( k > max_black )
		{
			max_black = k;
			memcpy( found, color, sizeof( color ) );
		}
	}
}

void main()
{
	int i, j, k, nEdges, T;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d %d", &nNodes, &nEdges );

		for ( i = 0; i <= nNodes; ++i )
		{
			adj[i].l.clear();
		}

		for ( i = 0; i < nEdges; ++i )
		{
			scanf( "%d %d", &j, &k );
			adj[j].l.push_back( k );
			adj[k].l.push_back( j );
		}

		max_black = 0;

		memset( used, 0, sizeof( used ) );

		call();

		printf( "%d\n", max_black );

		for ( i = 1; i <= nNodes; ++i )
		{
			if ( found[i] == 'B' )
			{
				printf( "%d", i );
				break;
			}
		}

		for ( ++i; i <= nNodes; ++i )
		{
			if ( found[i] == 'B' )
			{
				printf( " %d", i );
			}
		}

		printf( "\n" );
	}
}