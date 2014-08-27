//	THE BELLMAN-FORD ALGORITHM
//	TEST PROBLEM: 558 - WORMHOLES
//	RUN TIME EFFICIENCY: POOR

#include <stdio.h>
#include <string.h>

#define MAXNODE 1001
#define MAXEDGE 2001
#define INF 0xFFFFFFFF

int d[MAXNODE];	// distant matrix, stores the final outcome
int p[MAXNODE]; // predecessor matrix
int w[MAXNODE][MAXNODE]; // weight matrix
int nodes; // number of nodes
int edges; // number of edges

struct
{
	int u, v;
} edgelist[MAXEDGE];

void initialize_single_source( int s )
{
	int i;

	for ( i = 0; i < nodes; ++i )
	{
		d[i] = INF;
		p[i] = -1;
	}

	d[s] = 0;
}

void relax( int u, int v )
{
	if ( d[v] > d[u] + w[u][v] )
	{
		d[v] = d[u] + w[u][v];
		p[v] = u;
	}
}

bool bellman_ford( int s )
{
	int i, j;

	initialize_single_source( s );

	for ( i = 0; i < nodes - 1; ++i )
	{
		for ( j = 0; j < edges; ++j )
		{
			relax( edgelist[j].u, edgelist[j].v );
		}
	}

	for ( i = 0; i < edges; ++i )
	{
		if ( d[edgelist[i].v] > d[edgelist[i].u] + w[edgelist[i].u][edgelist[i].v] )
		{
			return false;
		}
	}

	return true;
}

void print_path( int s, int v )
{
	if ( v == s )
	{
		printf( "%d", s );
	}
	else
	{
		if ( p[v] = -1 )
		{
			printf( "no path from %d to %d exists\n", s, v );
		}
		else
		{
			print_path( s, p[v] );
		}
	}
}

int main()
{
	int i, d, tc;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while( tc-- )
	{
		scanf( "%d %d", &nodes, &edges );

		for ( i = 0; i < edges; ++i )
		{
			scanf( "%d %d %d", &edgelist[i].u, &edgelist[i].v, &d );
			w[edgelist[i].u][edgelist[i].v] = d;
		}

		if ( bellman_ford( 0 ) ) // NEGATIVE CYCLE EXISTS
		{
			printf( "not possible\n" );
		}
		else
		{
			printf( "possible\n" );
		}
	}

	return 0;
}







