#include <stdio.h>

char t[32][5][5][5][5][5][5];

int call( int s, int a, int b, int c, int d, int e, int f )
{		
	if ( s > 31 )
	{				
		return 1;
	}
	
	if ( s == 31 )
	{
		t[s][a][b][c][d][e][f] = -1;
		
		return -1;
	}
	
	if ( t[s][a][b][c][d][e][f] == 0 )
	{
		int w = -1;
		
		if ( a < 4 )
		{
			if ( call( s + 1, a + 1, b, c, d, e, f ) == -1 )
			{
				w = 1;
			}			
		}
		
		if ( b < 4 )
		{
			if ( call( s + 2, a, b + 1, c, d, e, f ) == -1 )
			{
				w = 1;
			}			
		}
		
		if ( c < 4 )
		{
			if ( call( s + 3, a, b, c + 1, d, e, f ) == -1 )
			{
				w = 1;
			}			
		}
		
		if ( d < 4 )
		{
			if ( call( s + 4, a, b, c, d + 1, e, f ) == -1 )
			{
				w = 1;
			}			
		}
		
		if ( e < 4 )
		{
			if ( call( s + 5, a, b, c, d, e + 1, f ) == -1 )
			{
				w = 1;
			}			
		}
		
		if ( f < 4 )
		{
			if ( call( s + 6, a, b, c, d, e, f + 1 ) == -1 )
			{
				w = 1;
			}			
		}
		
		t[s][a][b][c][d][e][f] = w;
	}
	
	return t[s][a][b][c][d][e][f];
}

void main()
{
	call( 0, 0, 0, 0, 0, 0, 0 );
	
	int s, a, b, c, d, e, f, i;
	
	char str[30];
	
	//freopen( "a.in", "r", stdin );
	
	while ( gets( str ) )
	{
		a = b = c = d = e = f = s = 0;		
		
		for ( i = 0; str[i]; ++i )
		{
			if ( str[i] == '1' )
			{
				++a;
				s += 1;
			}
			else if ( str[i] == '2' )
			{
				++b;
				s += 2;
			}
			else if ( str[i] == '3' )
			{
				++c;
				s += 3;
			}
			else if ( str[i] == '4' )
			{
				++d;
				s += 4;
			}
			else if ( str[i] == '5' )
			{
				++e;
				s += 5;
			}
			else if ( str[i] == '6' )
			{
				++f;
				s += 6;
			}			
		}
		
		printf( "%s ", str );
		
		if ( i % 2 == 0 )
		{
			if ( t[s][a][b][c][d][e][f] == 1 )
			{
				printf( "A\n" );
			}
			else
			{
				printf( "B\n" );
			}
		}
		else
		{
			if ( t[s][a][b][c][d][e][f] == 1 )
			{
				printf( "B\n" );
			}
			else
			{
				printf( "A\n" );
			}
		}
	}
}
