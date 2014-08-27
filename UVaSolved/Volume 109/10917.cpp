#include <stdio.h>
#include <vector>

using namespace std;

// DIJKSTRA ALGORITHM FOR SINGLE SOURCE SHORTEST PATH

#define INF 0x2FFFFFFF

#define MAXNODES 1010

// number of nodes
int nNodes;

struct adj_list	// adjacency list
{	
	vector <int> n; // adjacent nodes
	vector <int> w; // corresponding edge weight
}	node[MAXNODES + 1];

int parent [MAXNODES + 1];

int s_D[MAXNODES + 1];

int n_P[MAXNODES + 1];

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
		
		printf( " %d", u );
	}
	else
	{
		printf( "%d", u );
	}
}

void dijkstra( int start )
{	
	int distance[MAXNODES + 1], i, v;
	
	for ( i = 1; i <= nNodes; ++i )
	{	
		distance[i] = INF;	
		heap_position[i] = 0;
		parent[i] = -1;
	}
	
	distance[start] = 0;
	
	heap_size = 0;
	
	insert_heap( start, 0 );
	
	while ( heap_size )
	{
		v = extract_min();
		
		for ( i = 0; i < node[v].n.size(); ++i )
		{
			int j = node[v].n[i];
			int w = node[v].w[i];
			
			if ( w + distance[v] < distance[j] )
			{
				distance[j] = w + distance[v];
				parent[j] = v;
				decrease_key( j, w + distance[v] );
			}
		}		
	}
	
	for ( i = 1; i <= nNodes; ++i )
	{
		s_D[i] = distance[i];
	}
}

int call( int s )
{	
	if ( s == 2 )
	{
		return 1;
	}
	
	if ( n_P[s] != -1 )
	{
		return n_P[s];
	}
	
	int sum, i;
	
	sum = 0;
	
	for ( i = 0; i < node[s].n.size(); ++i )
	{
		int j = node[s].n[i];
		
		if ( s_D[j] < s_D[s] )
		{
			sum += call( j );
		}
	}
	
	n_P[s] = sum;
	
	return n_P[s];
}

void main()
{	
	int i, j, k, c, nEdges;
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &nNodes ) && nNodes )
	{		
		scanf( "%d", &nEdges );
		
		for ( i = 1; i <= nNodes; ++i )
		{		
			node[i].n.clear();
			node[i].w.clear();
		}
		
		for ( i = 1; i <= nEdges; ++i )
		{
			scanf( "%d %d %d", &j, &k, &c );
			
			node[j].n.push_back( k );
			node[j].w.push_back( c );
			
			node[k].n.push_back( j );
			node[k].w.push_back( c );
		}
				
		dijkstra( 2 );

		memset( n_P, -1, sizeof( n_P ) );
		
		printf( "%d\n", call( 1 ) );
	}
}
