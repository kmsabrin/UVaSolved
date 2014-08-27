#include <stdio.h>
#include <string.h>

char used[81][81];

char board[81][81];

char t, s;

int n;

char f;

int u, v;

void call( int i, int j, char c )
{
	if ( i < 0 || i >= n || j < 0 || j >= n || used[i][j] || board[i][j] != c || f )
	{
		return;
	}
	
	if ( t == 'w' && j == n - 1 )
	{
		f = 1;
		
		return;
	}
	else if ( t == 'b' && i == n - 1 )
	{
		f = 1;
		
		return;
	}
	else if ( t == 'u' )
	{
		if ( s == 'w' )
		{
			if ( j == 0 )
			{
				u = 1;
			}
			else if ( j == n - 1 )
			{
				v = 1;
			}

			if ( u && v )
			{
				f = 1;

				return;
			}
		}
		else if ( s == 'b' )
		{
			if ( i == 0 )
			{
				u = 1;
			}
			else if ( i == n - 1 )
			{
				v = 1;
			}

			if ( u && v )
			{
				f = 1;

				return;
			}			
		}		
	}
	
	used[i][j] = 1;
	
	
	call( i + 1, j, c );
	
	call( i - 1, j, c );
	
	call( i, j + 1, c );
	
	call( i, j - 1, c );
}

void main()
{
	int i, j;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) && n )
	{		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", board[i] );
		}
		
		f = 0;
		
		
		t = 'w';	

		memset( used, 0, sizeof( used ) );
		
		for ( i = 0; !f && i < n; ++i )
		{
			if ( !used[i][0] && board[i][0] == 'W' )
			{								
				call( i, 0, 'W' );
			}
		}
		
		if ( f ) 
		{
			printf( "White has a winning path.\n" );
			
			continue;
		}
		
		
		
		t = 'b';	
				
		for ( i = 0; !f && i < n; ++i )
		{
			if ( !used[0][i] && board[0][i] == 'B' )
			{								
				call( 0, i, 'B' );
			}
		}
		
		if ( f ) 
		{
			printf( "Black has a winning path.\n" );
			
			continue;
		}



		t = 'u';	

		s = 'w';
				
		for ( i = 0; !f && i < n; ++i )
		{
			for ( j = 0; !f && j < n; ++j )
			{
				if ( board[i][j] == 'U' )
				{
					board[i][j] = 'W';										

					u = v = 0;

					memset( used, 0, sizeof( used ) );
				
					call( i, j, 'W' );

					board[i][j] = 'U';
				}
			}
		}
		
		if ( f ) 
		{
			printf( "White can win in one move.\n" );
			
			continue;
		}

		
		s = 'b';
		
		for ( i = 0; !f && i < n; ++i )
		{
			for ( j = 0; !f && j < n; ++j )
			{
				if ( board[i][j] == 'U' )
				{
					board[i][j] = 'B';
					
					memset( used, 0, sizeof( used ) );

					u = v = 0;
				
					call( i, j, 'B' );

					board[i][j] = 'U';
				}
			}
		}
		
		if ( f ) 
		{
			printf( "Black can win in one move.\n" );
			
			continue;
		}


		printf( "There is no winning path.\n" );
	}
}




