#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// DIJKSTRA ALGORITHM FOR SINGLE SOURCE SHORTEST PATH

#define INF 0xFFFFFF

#define MAXNODES 20

// number of nodes
int nNodes;

struct adj_list	// adjacency list
{	
	vector <int> n; // adjacent nodes
	vector <int> w; // corresponding edge weight
}	node[MAXNODES + 1];

int parent[MAXNODES + 1];

char table[21][31];

int cost[21];

double sum;

// MINHEAP

struct heap
{
	int n; // node number
	int v; // node value
}	h[MAXNODES + 1]; // heap starts with array location 1

int heap_position[MAXNODES + 1]; // index of a node in the heap array, for fast look-up in decrease_key

int heap_size; // current size of heap

void insert_heap( int n, int v ) 
{
	int i = ++heap_size;
	
	while ( i > 1 && v < h[i / 2].v )
	{
		h[i].v = h[i / 2].v;
		h[i].n = h[i / 2].n;
		heap_position[h[i].n] = i;
		i = i / 2;
	}
	
	h[i].v = v;
	h[i].n = n;
	heap_position[h[i].n] = i;
}

void decrease_key( int n, int v )
{	
	int i = heap_position[n];
	
	if ( !i )
	{
		insert_heap( n, v );
		return;
	}
	
	while ( i > 1 &&  v < h[i / 2].v )
	{
		h[i].v = h[i / 2].v;
		h[i].n = h[i / 2].n;
		heap_position[h[i].n] = i;
		i = i / 2;
	}
	
	h[i].v = v;
	h[i].n = n;
	heap_position[h[i].n] = i;
}

int extract_min()
{
	int v = h[1].n;

	int i = 2;	
	int k = h[heap_size].v;
	int j = h[heap_size].n;
	
	--heap_size;
	
	while ( i <= heap_size )
	{
		if ( i < heap_size && h[i].v > h[i + 1].v )
		{
			i = i + 1;
		}
		
		if ( k <= h[i].v )
		{
			break;
		}
		
		h[i / 2].v = h[i].v;
		h[i / 2].n = h[i].n;
		heap_position[h[i / 2].n] = i / 2;
		
		i = 2 * i;
	}
	
	h[i / 2].v = k;
	h[i / 2].n = j;
	heap_position[h[i / 2].n] = i / 2;	

	return v;
}

void print_path( int u )
{
	if ( parent[u] != -1 )
	{
		print_path( parent[u] );

		printf( " %s", table[u] );		
	}
	else
	{
		printf( "%s", table[u] );		
	}
}

void dijkstra( int start, int end, int d )
{	
	int distance[MAXNODES + 1], i, v;
	
	for ( i = 0; i < nNodes; ++i )
	{	
		distance[i] = INF;	
		heap_position[i] = 0;
		parent[i] = -1;
	}
	
	distance[start] = cost[start];
		
	heap_size = 0;
	
	insert_heap( start, distance[start] );
		
	while ( heap_size )
	{
		v = extract_min();
		
		for ( i = 0; i < node[v].n.size(); ++i )
		{
			int j = node[v].n[i];
			int w = node[v].w[i];
			
			if ( w + distance[v] + cost[j] < distance[j] )
			{
				distance[j] = w + distance[v] + cost[j];
				parent[j]=  v;
				decrease_key( j, w + distance[v] + cost[j] );
			}
		}		
	}
	
	if ( start == end )
	{
		printf( "%s\n", table[start] );

		sum = distance[start];
	}
	else
	{
		sum = distance[end];

		print_path( end );

		printf( "\n" );
	}

	sum	+= ( sum * 10.0 ) / 100.0;

	printf( "Each passenger has to pay : %.2lf taka\n", sum / (double)d );		
}

void main()
{
	int i, j, p, q, c, d, T, kase = 0;

	int nEdges, nQuery;

	char s1[31], s2[31];

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d", &nNodes );

		for ( i = 0; i < nNodes; ++i )
		{
			scanf( "%s %d", table[i], &cost[i] );
			
			node[i].n.clear();
			node[i].w.clear();
		}

		scanf( "%d", &nEdges );

		for ( i = 0; i < nEdges; ++i )
		{
			scanf( "%s %s %d", s1, s2, &c );

			for ( j = 0; j < nNodes; ++j )
			{
				if ( !strcmp( s1, table[j] ) )
				{
					p = j;
				}
				else if ( !strcmp( s2, table[j] ) )
				{
					q = j;
				}
			}
			
			node[p].n.push_back( q );
			node[p].w.push_back( c * 2 );

			node[q].n.push_back( p );
			node[q].w.push_back( c * 2 );
		}

		printf( "Map #%d\n", ++kase );

		scanf( "%d", &nQuery );

		for ( i = 1; i <= nQuery; ++i )
		{
			scanf( "%s %s %d", s1, s2, &d );

			for ( j = 0; j < nNodes; ++j )
			{
				if ( !strcmp( s1, table[j] ) )
				{
					p = j;
				}
				else if ( !strcmp( s2, table[j] ) )
				{
					q = j;
				}
			}
	
			printf( "Query #%d\n", i );

			dijkstra( p, q, d );
		}

		if ( T )
		{
			printf( "\n" );
		}
	}
}






