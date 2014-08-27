#include <stdio.h>
#include <string.h>

#define MAXNODES 401
#define SIZE 100001 //	maximum queue size

bool a[MAXNODES][MAXNODES];  // adjancency matrix array, true iff edge exits
bool visited[MAXNODES]; // true iff already visited
int parent[MAXNODES];  // initialized to -1, required to find path
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

int bfs( int s, int t )
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

			if ( visited[t] == true )
			{
				break;
			}
		}
	}

	return length[t];
}

bool connected( char a[], char b[] )
{	
	int i, j;

	if ( strlen( a ) != strlen( b ) )
	{
		return false;
	}

	for ( i = j = 0; i < ( int )strlen( a ); ++i )
	{
		if ( a[i] != b[i] )
		{
			++j;
		}

		if ( j > 1 )
		{
			return false;
		}
	}

	if ( j = 0 )
	{
		return false;
	}

	return true;
}

int main()
{
	int i, j, u, v, tc;
	char table[401][21], str[21], s[21], d[21], *p;

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &tc );

	while ( tc-- )
	{

		i = 0;

		while ( 1 )
		{
			gets( str );

			if ( strcmp( str, "*" ) == 0 )
			{
				break;
			}

			strcpy( table[i], str );

			++i;
		}

		nodes = i;

		for ( i = 0; i < nodes; ++i )
		{
			for ( j = 0; j < nodes; ++j )
			{
				a[i][j] = a[j][i] = connected( table[i], table[j] );
			}
		}

		while ( gets( str ) && str[0] != NULL )
		{
			p = strtok( str, " " );
			
			strcpy( s, p );

			p = strtok( NULL, " " );

			strcpy( d, p );

			for ( i = 0; i < nodes; ++i )
			{
				if ( strcmp( table[i], s ) == 0 ) 
				{
					u = i;
				}

				if ( strcmp( table[i], d ) == 0 ) 
				{
					v = i;
				}
			}

			printf( "%s %s %d\n", s, d, bfs( u, v ) );
		}

		if ( tc )
		{
			printf( "\n" );
		}
	}

	return 0;
}