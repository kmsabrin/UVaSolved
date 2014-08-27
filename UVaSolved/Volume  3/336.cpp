#include <stdio.h>
#include <string.h>

#define MAXNODES 51
#define SIZE 10001 // maximum queue size

bool a[MAXNODES][MAXNODES]; // adjancency matrix array, true iff edge exits
bool visited[MAXNODES]; // true iff already visited
int parent[MAXNODES]; // initialized to -1, required to find path
int length[MAXNODES];	// contains the bfs tree length from source to nodes
int nodes;  // number of nodes

int head, tail, count; // queue variables
struct
{
	int x; // can be extended to multiple element holding queue
} q[SIZE];

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

bool empty()
{
	if ( count == 0 )
	{
		return true;
	}
	return false;
}

void print_path( int u )
{
	if ( parent[u] != -1 )
		print_path( parent[u] );
	//printf( u );
}

void bfs( int s )
{
	int i;

	init_queue();
	memset( visited, false, sizeof( visited ) );
	memset( parent, -1, sizeof( parent ) );
	memset( length, -1, sizeof( length ) );

	visited[s] = true;
	length[s] = 0;
	push( s );

	while ( empty() == false )
	{
		pop( s );

		for ( i = 0; i < nodes; ++i )
		{
			if ( a[s][i] == true && visited[i] == false )
			{
				visited[i] = true;
				parent[i] = s;
				length[i] = length[s] + 1;
				push( i );
			}
		}
	}
}

int main()
{
	int node[MAXNODES];
	int n, u, v, r, s, t;
	int i, j, cnt;
	int tc = 1;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while( 1 )
	{	
		scanf( "%d", &n );

		if ( n == 0 )
		{
			break;
		}
		
		memset( a, false, sizeof( a ) );
		
		for ( i = cnt = 0; i < n; ++i )
		{
			scanf( "%d %d", &r, &s );

			u = v = -1;

			for ( j = 0; j < cnt; ++j )
			{
				if ( node[j] == r )
				{
					u = j;
				}

				if ( node[j] == s )
				{
					v = j;
				}
			}

			if ( u == -1 )
			{
				u = cnt++;
				node[u] = r;
			}
						
			if ( v == -1 )
			{
				if ( r != s )
				{
					v = cnt++;
					node[v] = s;
				}
				else
				{
					v = u;
				}
			}
		
			if ( u != v )
			{
				a[u][v] = a[v][u] = true;
			}
			
		}

		nodes = cnt;				
		
		while ( 1 )
		{
			scanf( "%d %d", &s, &t );

			if ( s == 0 && t == 0 )
			{
				break;
			}
			
			for ( i = 0; i < cnt; ++i )
			{
				if ( node[i] == s )
				{
					bfs( i );											
					break;
				}
			}
											
			for ( j = r = 0; j < nodes; ++j )
			{						
				if ( length[j] < 0 || length[j] > t )
					++r;
			}
			
			printf( "Case %d: %d nodes not reachable from node %d with TTL = %d.\n", tc++, r, s, t );						
		}
	}

	return 0;
}