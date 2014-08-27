#include <stdio.h>
#include <string.h>

#define MAX 1001
#define SIZE 1000001

bool board[MAX][MAX];
bool visited[MAX][MAX];
int length[MAX][MAX];
int R, C;

int head, tail, count;
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

bool empty()
{
	if ( count == 0 )
	{
		return true;
	}
	return false;
}

bool valid_position( int x, int y )
{
	if ( x < 0 || x >= R || y < 0 || y >= C )
	{
		return false;
	}
	return true;
}

int bfs( int sx, int sy, int tx, int ty )
{
	int x, y;
		
	visited[sx][sy] = true;
	length[sx][sy] = 0;
	push( sx, sy );

	while ( empty() == false )
	{				
		pop( x, y );
											
		if ( valid_position( x - 1, y ) == true )
		{			
			if ( visited[x - 1][y] == false && board[x - 1][y] == false )
			{				
			    visited[x - 1][y] = true;				
				length[x - 1][y] = length[x][y] + 1;
				push( x - 1, y );			
			}
		}

		if ( valid_position( x + 1, y ) == true )
		{			
			if ( visited[x + 1][y] == false && board[x + 1][y] == false )
			{				
			    visited[x + 1][y] = true;				
				length[x + 1][y] = length[x][y] + 1;
				push( x + 1, y );				
			}
		}

		if ( valid_position( x, y - 1 ) == true )
		{			
			if ( visited[x][y - 1] == false && board[x][y - 1] == false )
			{				
			    visited[x][y - 1] = true;				
				length[x][y - 1] = length[x][y] + 1;
				push( x, y - 1 );			
			}
		}

		if ( valid_position( x, y + 1 ) == true )
		{			
			if ( visited[x][y + 1] == false && board[x][y + 1] == false )
			{				
			    visited[x][y + 1] = true;				
				length[x][y + 1] = length[x][y] + 1;
				push( x, y + 1 );
			}			
		}

		if ( visited[tx][ty] == true )
		{
			break;
		}
	}

	return 0;
}

int main()
{
	int i, j, k, r, s, sx, sy, tx, ty ;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	
	while ( scanf( "%d %d", &R, &C ) )
	{
			
		if ( R == 0 && C == 0 )
		{
			break;
		}
			
		memset( board, false, sizeof( board ) );

		scanf( "%d", &j );		

		for ( i = 0; i < j; ++i )
		{
			scanf( "%d %d", &k, &r );

			while ( r-- )
			{
				scanf( "%d", &s );
				board[k][s] = true;
			}
		}

		scanf( "%d %d %d %d", &sx, &sy, &tx, &ty );
			
		memset( visited, false, sizeof( visited ) );		
		memset( length, -1, sizeof( length ) );		
		init_queue();

		bfs( sx, sy, tx, ty );					

		printf( "%d\n", length[tx][ty] );
	}

	return 0;
}

