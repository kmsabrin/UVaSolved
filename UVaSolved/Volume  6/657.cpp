#include <stdio.h>
#include <stdlib.h>

int comp( const void *i, const void *j )
{
	return *( int * )i - *( int * )j;
}

char board[51][51];
int r[100000];
int w, h, count;

int find_dot( int i, int j )
{

	if ( i < 0 || j < 0 || i >= h || j >= w || board[i][j] != 'X' )
	{
		return 0;
	}

	board[i][j] ='*';
	
	find_dot( i + 1, j );
	find_dot( i - 1, j );
	find_dot( i, j + 1 );
	find_dot( i, j - 1 );

	return 0;

}
	
int find_dice( int i, int j )
{

	if ( i < 0 || j < 0 || i >= h || j >= w || board[i][j] == '.' )
	{
		return 0;
	}

	if ( board[i][j] == 'X' )
	{		
		++count;		
		find_dot( i, j );		
	}

	board[i][j] = '.';
	
	find_dice( i + 1, j );
	find_dice( i - 1, j );
	find_dice( i, j + 1 );
	find_dice( i, j - 1 );

	return 0;

}

int main()
{

	int i, j, k, t = 0;	

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	
	while ( scanf( "%d %d", &w, &h ) )
	{
	
		if ( w == 0 && h == 0 )
		{
			break;
		}
		
		for ( i = 0; i < h; ++i )
		{			
			scanf( "%s", board[i] );
		}		

		k = 0;
		for ( i = 0; i < h; ++i )
		{
			for ( j = 0; j < w; ++j )
			{
				if ( board[i][j] == '*' )
				{
					count = 0;
					find_dice( i, j );
					r[k++] = count;
				}
			}
		}

		qsort( r, k, sizeof( int ), comp );

		printf( "Throw %d\n", ++t );

		printf( "%d", r[0] );
		for ( i = 1; i < k; ++i )
		{
			printf( "% d", r[i] );
		}
		printf( "\n\n" );

	}

	return 0;

}

