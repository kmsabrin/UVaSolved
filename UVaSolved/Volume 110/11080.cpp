#include <stdio.h>
#include <string.h>

#define MAXNODES 200
#define SIZE 200

char a[MAXNODES + 10][MAXNODES + 10];
char visited[MAXNODES + 10];
char color[MAXNODES + 10];
char self[MAXNODES + 10];
char used[MAXNODES + 10];
int nNodes;

int m;

int head, tail, count;

struct
{
	int x;
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

void bfs( int s )
{
	int i;

	init_queue();
	
	memset( visited, 0, sizeof( visited ) );
	
	visited[s] = 1;	
	push( s );
	
	while ( !empty() )
	{
		pop( s );
		
		for ( i = 0; i < nNodes; ++i )
		{
			if ( a[s][i] && !visited[i] )
			{
				visited[i] = 1;
				
				color[i] = color[s] ^ 1;
				
				push( i );
			}
		}
	}	
}

void check()
{
	int i, j, f;
	int r;
	
	for ( i = r = 0; i < nNodes; ++i )
	{
		if ( visited[i] )
		{
			if ( color[i] == 0 && self[i] == 1 )
			{				
				return;
			}
			
			f = 0;

			for ( j = 0; j < nNodes; ++j )
			{
				if ( a[i][j] && ( color[i] == color[j] ) )
				{					
					return;
				}

				if ( a[i][j] )
				{
					f = 1;
				}
			}

			if ( color[i] == 0 && f == 0 )
			{
				return;
			}
			
			if ( color[i] == 0 )
			{
				++r;
			}
		}
	}
	
	if ( r > m )
	{
		m = r;
	}				
}

void main()
{
	int i, j, k, e, r, T;
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &T );
	
	while ( T-- )
	{
		scanf( "%d %d", &nNodes, &e );
		
		memset( a, 0, sizeof( a ) );
		memset( self, 0, sizeof( self ) );
		
		for ( i = 0; i < e; ++i )
		{
			scanf( "%d %d", &j, &k );
			
			a[j][k] = a[k][j] = 1;
			
			if ( j == k )
			{
				self[j] = 1;
			}
		}						
		
		memset( color, -1, sizeof( used ) );
		memset( used, 0, sizeof( used ) );
		
		for ( i = r = 0; i < nNodes; ++i )
		{						
			if ( used[i] == 0 )
			{		
				m = -1;

				color[i] = 0;
				bfs( i );
				check();
				
				color[i] = 1;
				bfs( i );
				check();				
				
				
				for ( j = 0; j < nNodes; ++j )
				{
					if ( visited[j] == 1 )
					{
						used[j] = 1;
					}
				}
				
				if ( m == -1 )
				{
					r = nNodes + 1;
					break;
				}
				else
				{
					r += m;
				}
			}						
		}
				
		printf( "%d\n", nNodes - r );
	}
}




