#include <stdio.h>
#include <string.h>

#define MAXNODES 1001
#define SIZE 1000001 // maximum queue size

bool a[MAXNODES][MAXNODES]; // adjancency matrix array, true iff edge exits
bool visited[MAXNODES]; // true iff already visited
int parent[MAXNODES]; // initialized to -1, required to find path
int length[MAXNODES];	// contains the bfs tree length from source to nodes
int nodes;  // number of nodes

char node[MAXNODES][5];

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

void print_path( int s, int t )
{
	if ( parent[t] != s )
		print_path( s, parent[t] );

	printf( "%s %s\n", node[parent[t]], node[t] );
}

void bfs( int s, int t )
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

		if ( visited[t] == true )
		{
			break;
		}
	}
}

int main()
{
	
	char s1[5], s2[5];	
	int n, u, v, s, t;
	int i, j, cnt;
	int f = 0;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while( 1 )
	{	
		if ( scanf( "%d", &n ) == EOF )
		{
			break;
		}
		
		if ( f )
		{
			scanf( "\n" );
			printf( "\n" );
		}
		f = 1;
		
		memset( a, false, sizeof( a ) );
		
		for ( i = cnt = 0; i < n; ++i )
		{
			scanf( "%s %s", &s1, &s2 );

			u = v = -1;

			for ( j = 0; j < cnt; ++j )
			{
				if ( strcmp( node[j], s1 ) == 0 )
				{
					u = j;
				}

				if ( strcmp( node[j], s2 ) == 0 )
				{
					v = j;
				}
			}

			if ( u == -1 )
			{
				u = cnt++;
				strcpy( node[u], s1 );
			}
						
			if ( v == -1 )
			{
				v = cnt++;
				strcpy( node[v], s2 );
			}
									
			a[u][v] = a[v][u] = true;
			
			
		}

		nodes = cnt;				
						
		scanf( "%s %s", s1, s2 );

		for ( i = 0; i < nodes; ++i )
		{
			if ( strcmp( node[i], s1 ) == 0 )
			{
				s = i;
			}

			if ( strcmp( node[i], s2 ) == 0 )
			{
				t = i;
			}
		}
	
		bfs( s, t );

		if ( visited[t] == false )
		{
			printf( "No route\n" );
		}
		else
		{
			print_path( s, t );
		}

	}
	return 0;
}