#include <stdio.h>
#include <string.h>

#define MAXNODES 7
#define SIZE 49

char wall[MAXNODES][MAXNODES][MAXNODES][MAXNODES];
char visited[MAXNODES][MAXNODES];
char parent[MAXNODES][MAXNODES];
int R, C; 
int sx, sy, tx, ty;

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
	if ( x < 1 || x > R || y < 1 || y > C )
	{
		return false;
	}
	return true;
}

int bfs()
{
	int x, y;

	init_queue();
	memset( visited, 0, sizeof( visited ) );
	memset( parent, -1, sizeof( parent ) );

	visited[sx][sy] = true;
	push( sx, sy );

	while ( empty() == false )
	{		
		pop( x, y );			

		if ( valid_position( x - 1, y ) == true )
		{
			if ( visited[x - 1][y] == 0 && wall[x][y][x - 1][y] == 0 )
			{				
			    visited[x - 1][y] = 1;				
				parent[x - 1][y] = 1;
				push( x - 1, y );
			}
		}

		if ( valid_position( x + 1, y ) == true )
		{
			if ( visited[x + 1][y] == 0 && wall[x][y][x + 1][y] == 0 )
			{			
			    visited[x + 1][y] = 1;
				parent[x + 1][y] = 2;
				push( x + 1, y );
			}
		}

		if ( valid_position( x, y - 1 ) == true )
		{
			if ( visited[x][y - 1] == 0 && wall[x][y][x][y - 1] == 0 )
			{			
			    visited[x][y - 1] = 1;
				parent[x][y - 1] = 3;
				push( x, y - 1 );
			}
		}

		if ( valid_position( x, y + 1 ) == true )
		{
			if ( visited[x][y + 1] == 0 && wall[x][y][x][y + 1] == 0 )
			{			
			    visited[x][y + 1] = 1;
				parent[x][y + 1] = 4;
				push( x, y + 1 );
			}
		}

		if ( visited[tx][ty] == 1 )
		{
			break;
		}
	}

	return 0;
}

int call( int a, int b )
{
	if ( a == sx && b == sy )
	{
		return 0;
	}

	if ( parent[a][b] == 1 )
	{
		call( a + 1, b );
		printf( "N" );
	}
	else if ( parent[a][b] == 2 )
	{
		call( a - 1, b );
		printf( "S" );
	}
	else if ( parent[a][b] == 3 )
	{
		call( a, b + 1 );
		printf( "W" );
	}
	else 
	{
		call( a, b - 1 );
		printf( "E" );
	}

	return 0;
}

int main()
{
	int i, j, a, b, c, d;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	R = C = 6;

	while ( 1 )
	{
		scanf( "%d %d", &sy, &sx );

		if ( sy == 0 && sx == 0 )
		{
			break;
		}

		scanf( "%d %d", &ty, &tx );

		memset( wall, 0, sizeof( wall ) );
		
		for ( j = 1; j <= 3; ++j )
		{
			scanf( "%d %d %d %d", &a, &b, &c, &d );

			if ( a == c )
			{
				for ( i = b + 1; i <= d; ++i )
				{
					wall[i][a][i][a + 1] = 1;
					wall[i][a + 1][i][a] = 1;	
				}
			}
			else
			{
				for ( i = a + 1; i <= c; ++i )
				{
					wall[b][i][b + 1][i] = 1;
					wall[b + 1][i][b][i] = 1;					
				}
			}
		}
				
		bfs();

		call( tx, ty );

		printf( "\n" );
	}

	return 0;
}

