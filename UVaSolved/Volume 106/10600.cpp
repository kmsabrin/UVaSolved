#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEDGE 4950
#define MAXNODE 100
#define SIZE 100

struct elist
{
	int u, v;	
	int d;
} edgelist[MAXEDGE + 10];

int p[MAXNODE + 10]; // parent field used by set operations
int nodes; // number of nodes
int edges; // number of edges

char taken[MAXNODE + 10];

int adj[MAXNODE + 10][MAXNODE + 10];

int max[MAXNODE + 10][MAXNODE + 10];

void initialize_set( int n )
{
	for ( int i = 1; i <= n; ++i )
	{
		p[i] = -1;
	}
}

int collapsing_find( int i ) // finds the root of i
{
	int r = i;

	while ( p[r] > 0 )
	{
		r = p[r];
	}

	while ( i != r )
	{
		int s = p[i];
		p[i] = r;
		i = s;
	}

	return r;
}

int weighted_union( int i, int j ) // joins member i and j
{
	i = collapsing_find( i );   // root of i
	j = collapsing_find( j );   // root of j

	if ( i == j )     // repitition check, within the same set
	{
		return 0;
	}

	int tmp = p[i] + p[j];

	if ( p[i] > p[j] )
	{
		p[i] = j;
		p[j] = tmp;
	}
	else
	{
		p[j] = i;
		p[i] = tmp;
	}

	return 1;
}

int comp( const void *i, const void *j )
{
	struct elist *p = ( struct elist * )i;
	struct elist *q = ( struct elist * )j;
	return p->d - q->d;
}

int head, tail, count; // queue variables

struct
{
	int x; // can be extended to multiple element holding queue
} q[SIZE + 10];

void init_queue()
{
	head = 0;
	tail = SIZE - 1;
	count = 0;
}

void push( int u )
{
	tail = ( tail + 1 ) % SIZE;
	q[tail].x = u;
	++count;
}

void pop( int &u )
{
	u = q[head].x;
	head = ( head + 1 ) % SIZE;
	--count;
}

int empty()
{
	if ( count == 0 )
	{
		return 1;
	}
	return 0;
}

char visited[MAXNODE + 10]; // true iff already visited

void bfs( int s )
{
	int i, h, mx;

	init_queue();
	memset( visited, 0, sizeof( visited ) );

	h = s;

	visited[h] = 1;
	push( h );

	mx = 0;
	

	while ( empty() == 0 )
	{
		pop( s );

		for ( i = 1; i <= nodes; ++i )
		{
			if ( adj[s][i] && visited[i] == 0 )
			{
				visited[i] = 1;
				
				if ( adj[s][i] > max[h][s] )
				{					
					max[h][i] = adj[s][i];
				}
				else
				{
					max[h][i] = max[h][s];
				}

				//printf( "%d %d %d\n", h, i, max[h][i] );
				
				push( i );
			}
		}
	}

	//printf( "\n" );
}

int kruskal()
{
	qsort( edgelist, edges, sizeof( edgelist[0] ), comp );

	initialize_set( nodes );

	int cnt, len, i;

	memset( taken, 0, sizeof( taken ) );
	memset( adj, 0, sizeof( adj ) );

	for ( i = cnt = len = 0; i < edges; ++i )
	{
		if ( weighted_union( edgelist[i].u, edgelist[i].v ) )
		{
				len += edgelist[i].d;				
				++cnt;
				taken[i] = 1;
				adj[edgelist[i].u][edgelist[i].v] = adj[edgelist[i].v][edgelist[i].u] = edgelist[i].d;
				//printf( "%d %d %d\n", edgelist[i].u, edgelist[i].v, edgelist[i].d );
		}

		if ( cnt == nodes - 1 )
		{
			break;
		}
	}

	return len;
}

void main()
{
	int t, i, mst, min, tmp;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	scanf( "%d", &t );

	while ( t-- )
	{
		scanf( "%d %d", &nodes, &edges );

		for ( i = 0; i < edges; ++i )
		{
			scanf( "%d %d %d", &edgelist[i].u, &edgelist[i].v, &edgelist[i].d );
		}

		mst = kruskal();

		memset( max, 0, sizeof( max ) );

		for ( i = 1; i <= nodes; ++i )
		{			
			bfs( i );
		}

		min = 1000;

		for ( i = 0; i < edges; ++i )
		{
			if ( taken[i] == 0 )
			{
				tmp = edgelist[i].d - max[edgelist[i].u][edgelist[i].v];

				if ( tmp < min )
				{
					min = tmp;
				}
			}
		}

		printf( "%d %d\n", mst, mst + min );
	}
}
