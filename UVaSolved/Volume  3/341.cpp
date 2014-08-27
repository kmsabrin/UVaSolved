//	THE BELLMAN-FORD ALGORITHM
//	TEST PROBLEM: 341 - NonStopTravel
//	RUN TIME EFFICIENCY: POOR

#include <stdio.h>
#include <string.h>

#define MAXNODE 11
#define MAXEDGE 101
#define INF 0xFFFFFFF

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

	for ( i = 1; i <= nodes; ++i )
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

void bellman_ford( int s )
{
	int i, j;

	initialize_single_source( s );

	for ( i = 1; i <= nodes - 1; ++i )
	{
		for ( j = 0; j < edges; ++j )
		{
			relax( edgelist[j].u, edgelist[j].v );
		}
	}
}

void print_path( int s, int v )
{

	if ( v == s )
	{
		printf( " %d", s );
	}
	else
	{
		if ( p[v] == -1 )
		{
			printf( "no path from %d to %d exists\n", s, v );
		}
		else
		{
			print_path( s, p[v] );
			printf( " %d", v );
		}
	}
}

int main()
{
	int i, j, k, cnt, dist, tc = 0;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while( 1 )
	{
		scanf( "%d", &nodes );

		if ( nodes == 0 )
		{
			break;
		}

		cnt = 0;

		for ( i = 1; i <= nodes; ++i )
		{
			scanf( "%d", &j );
			for ( k = 0; k < j; ++k )
			{
				edgelist[cnt].u = i;
				scanf( "%d %d", &edgelist[cnt].v, &dist );
				w[edgelist[cnt].u][edgelist[cnt].v] = dist;
				++cnt;
			}
		}

		edges = cnt;

		scanf( "%d %d", &j, &k );

		bellman_ford( j );

		printf( "Case %d: Path =", ++tc ); 

		print_path( j, k );
		
		printf( "; %d second delay\n", d[k] );

	}

	return 0;
}







