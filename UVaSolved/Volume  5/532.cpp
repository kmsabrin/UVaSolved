#include <stdio.h>
#include <string.h>

#define MAX 31
#define SIZE 901

char board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int length[MAX][MAX][MAX];
int L, R, C;

int head, tail, count;
struct
{
	int l, x, y;
} q[SIZE];

void init_queue()
{
	head = 0;
	tail = SIZE - 1;
	count = 0;
}

void push( int t, int u, int v )
{
	tail = ( tail + 1 ) % SIZE;
	q[tail].l = t, q[tail].x = u, q[tail].y = v;
	++count;
}

void pop( int &t, int &u, int &v )
{
	t = q[head].l, u = q[head].x, v = q[head].y;
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

bool valid_position( int l, int x, int y )
{
	if ( l < 0 || l >= L || x < 0 || x >= R || y < 0 || y >= C )
	{
		return false;
	}
	return true;
}

void bfs( int sl, int sx, int sy, int tl, int tx, int ty  )
{
	int l, x, y;
		
	visited[sl][sx][sy] = true;
	length[sl][sx][sy] = 0;
	push( sl, sx, sy );

	while ( empty() == false )
	{				
		pop( l, x, y );
											
		if ( valid_position( l, x - 1, y ) == true )
		{			
			if ( visited[l][x - 1][y] == false && board[l][x - 1][y] != '#' )
			{				
			    visited[l][x - 1][y] = true;				
				length[l][x - 1][y] = length[l][x][y] + 1;
				push( l, x - 1, y );										
			}
		}

		if ( valid_position( l, x + 1, y ) == true )
		{			
			if ( visited[l][x + 1][y] == false && board[l][x + 1][y] != '#'  )
			{				
			    visited[l][x + 1][y] = true;				
				length[l][x + 1][y] = length[l][x][y] + 1;
				push( l, x + 1, y );				
			}
		}

		if ( valid_position( l, x, y - 1 ) == true )
		{			
			if ( visited[l][x][y - 1] == false && board[l][x][y - 1] != '#'  )
			{				
			    visited[l][x][y - 1] = true;				
				length[l][x][y - 1] = length[l][x][y] + 1;
				push( l, x, y - 1 );					
			}
		}

		if ( valid_position( l, x, y + 1 ) == true )
		{			
			if ( visited[l][x][y + 1] == false && board[l][x][y + 1] != '#'  )
			{				
			    visited[l][x][y + 1] = true;				
				length[l][x][y + 1] = length[l][x][y] + 1;
				push( l, x, y + 1 );
			}			
		}

		if ( valid_position( l + 1, x, y ) == true )
		{			
			if ( visited[l + 1][x][y] == false && board[l + 1][x][y] != '#'  )
			{				
			    visited[l + 1][x][y] = true;				
				length[l + 1][x][y] = length[l][x][y] + 1;
				push( l + 1, x, y );
			}			
		}

		if ( valid_position( l - 1, x, y ) == true )
		{			
			if ( visited[l - 1][x][y] == false && board[l - 1][x][y] != '#'  )
			{				
			    visited[l - 1][x][y] = true;				
				length[l - 1][x][y] = length[l][x][y] + 1;
				push( l - 1, x, y );
			}			
		}
		
		if ( visited[tl][tx][ty] == true )
		{
			printf( "Escaped in %d minute(s).\n", length[tl][tx][ty] );
			return;
		}
		
	}

	printf( "Trapped!\n" );

}

int main()
{
	int i, j, k;
	int sl, sx, sy, tl, tx, ty; 

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	
	while ( scanf( "%d %d %d\n", &L, &R, &C ) )
	{
				
		if ( L == 0 && R == 0 && C == 0 )
		{
			break;
		}

		for ( i = 0; i < L; ++i )
		{
			for ( j = 0; j < R; ++j )
			{
				gets( board[i][j] );
			}				
			getchar();
		}

		for ( i = 0; i < L; ++i )
		{
			for ( j = 0; j < R; ++j )
			{
				for ( k = 0; k < C; ++k )
				{
					if ( board[i][j][k] == 'S' )
					{
						sl = i; sx = j; sy = k;
					}

					if ( board[i][j][k] == 'E' )
					{
						tl = i; tx = j; ty = k;
					}
				}
			}			
		}
		
		memset( visited, false, sizeof( visited ) );
		memset( length, -1, sizeof( length ) );
		init_queue();

		bfs( sl, sx, sy, tl, tx, ty );					

	}

	return 0;
}

