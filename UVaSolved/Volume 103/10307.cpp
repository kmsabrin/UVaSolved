#include <stdio.h>
#include <string.h>

#define INF 0x7fffffff
#define MAXNODES 101
#define SIZE 101

char visited[50 + 10][50 + 10];
int board[50 + 10][50 + 10]; // used to represent obstacles in the grid
int length[50 + 10][50 + 10]; // counts the minimum steps from source 
int adj[MAXNODES + 10][MAXNODES + 10];
int R, C; // row and column dimension of grid
int nNodes;
int mst_length;

int head, tail, count; // queue varibles

struct
{
	int x, y;
} q[SIZE];

void init_queue()
{
	head = 0;
	tail = SIZE - 1;
	count = 0;
}

void push( int u, int v )
{
	tail = ( tail + 1 ) % SIZE;
	q[tail].x = u, q[tail].y = v;
	++count;
}

void pop( int &u, int &v )
{
	u = q[head].x, v = q[head].y;
	head = ( head + 1 ) % SIZE;
	--count;
}

int empty()
{
	if ( !count )
	{
		return 1;
	}

	return 0;
}

int valid_position( int x, int y )
{
	if ( x < 0 || x >= R || y < 0 || y >= C || board[x][y] == -1 )
	{
		return 0;
	}

	return 1;
}

void bfs( int sx, int sy )
{
	int x, y;

	init_queue();

	memset( visited, 0, sizeof( visited ) );

	visited[sx][sy] = 1;
	length[sx][sy] = 0;
	push( sx, sy );

	while ( !empty() )
	{
		pop( x, y );

		if ( valid_position( x - 1, y ) )
		{
			if ( !visited[x - 1][y] )
			{
			    visited[x - 1][y] = 1;
				length[x - 1][y] = length[x][y] + 1;
				adj[board[sx][sy]][board[x - 1][y]] = adj[board[x - 1][y]][board[sx][sy]] = length[x - 1][y];
				push( x - 1, y );
			}
		}

		if ( valid_position( x + 1, y ) )
		{
			if ( !visited[x + 1][y] )
			{
			    visited[x + 1][y] = 1;
				length[x + 1][y] = length[x][y] + 1;
				adj[board[sx][sy]][board[x + 1][y]] = adj[board[x + 1][y]][board[sx][sy]] = length[x + 1][y];
				push( x + 1, y );
			}
		}

		if ( valid_position( x, y - 1 ) )
		{
			if ( !visited[x][y - 1] )
			{
			    visited[x][y - 1] = 1;
				length[x][y - 1] = length[x][y] + 1;
				adj[board[sx][sy]][board[x][y - 1]] = adj[board[x][y - 1]][board[sx][sy]] = length[x][y - 1];
				push( x, y - 1 );
			}
		}

		if ( valid_position( x, y + 1 ) )
		{
			if ( !visited[x][y + 1] )
			{
			    visited[x][y + 1] = 1;
				length[x][y + 1] = length[x][y] + 1;
				adj[board[sx][sy]][board[x][y + 1]] = adj[board[x][y + 1]][board[sx][sy]] = length[x][y + 1];
				push( x, y + 1 );
			}
		}
	}	
}


void prim( int start ) // start is the root(arbitrary) node passed to prim function
{
	int i, v, f, min;
	char intree[MAXNODES + 10]; // true iff node already processed or used
	int distance[MAXNODES + 10]; // this is the key array as defined in cormen

	for ( i = 1; i <= nNodes; ++i ) // initialization
	{
		intree[i] = 0;
		distance[i] = INF;		
	}

	mst_length = 0;
	distance[start] = 0;
	v = start;
	f = 1;

	while ( f )
	{
		intree[v] = 1;

		mst_length += distance[v];

		for ( i = 1; i <= nNodes; ++i ) 
		{
			if ( !intree[i] && adj[v][i] != -1 && adj[v][i] < distance[i] )
			{
				distance[i] = adj[v][i];								
			}
		}

		v = 0;
		f = 0;
		min = INF;

		for ( i = 1; i <= nNodes; ++i )
		{
			if ( !intree[i] && distance[i] < min )
			{
				min = distance[i];
				v = i;
				f = 1;
			}
		}
	}

	printf( "%d\n", mst_length );
}

int main()
{
	int i, j, k, tc;
	char str[60][60];

	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d %d\n", &C, &R );
		
		for ( i = 0; i < R; ++i )
		{
			gets( str[i] );
		}

		for ( i = 0, k = 0; i < R; ++i )
		{
			for ( j = 0; j < C; ++j )
			{
				if ( str[i][j] == '#' )
				{
					board[i][j] = -1;
				}
				else if ( str[i][j] == 32 )
				{
					board[i][j] = 0;
				}
				else
				{
					board[i][j] = ++k;
				}
			}
		}

		nNodes = k;
		
		memset( adj, -1, sizeof( adj ) );

		for ( i = 0; i < R; ++i )
		{
			for ( j = 0; j < C; ++j )
			{		
				if ( board[i][j] > 0 )
				{
					bfs( i, j );
				}
			}
		}
		
		prim( 1 );
	}

	return 0;
}

