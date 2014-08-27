#include <stdio.h>
#include <vector>

using namespace std;

// DIJKSTRA ALGORITHM FOR SINGLE SOURCE SHORTEST PATH

#define INF 0x7FFFFFF0

#define MAXNODES 10000

// number of nodes
int nNodes;

struct adj_list	// adjacency list
{	
	vector <int> n; // adjacent nodes
	vector <int> w; // corresponding edge weight
}	node[MAXNODES + 1];

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

void extract_min( int &v )
{
	int i = 1;	
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
}

void dijkstra( int start, int end )
{	
	int distance[MAXNODES + 1], i, v;
	
	for ( i = 0; i < nNodes; ++i )
	{	
		distance[i] = INF;	
		heap_position[i] = 0;
	}
	
	distance[start] = heap_size = 0;
	
	insert_heap( start, 0 );
	
	while ( heap_size )
	{
		extract_min( v );
		
		for ( i = 0; i < node[v].n.size(); ++i )
		{
			int j = node[v].n[i];
			int w = node[v].w[i];
			
			if ( w + distance[v] < distance[j] )
			{
				distance[j] = w + distance[v];
				decrease_key( j, w + distance[v] );
			}
		}		
	}	
}

void main()
{
	//
}