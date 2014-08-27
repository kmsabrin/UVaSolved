#include <stdio.h>
#include <string.h>

#define INF 0xFFFFFF

int a[1002][1002];

char b[1002][1002];

char s[1002];

void print_palindrome( int i, int j )
{
	if ( i == j )
	{
		printf( "%c", s[i] );
		
		return;
	}
	
	if ( b[i][j] == 1 )
	{
		printf( "%c", s[j] );
		
		print_palindrome( i + 1, j - 1 );
		
		printf( "%c", s[j] );
	}
	else if ( b[i][j] == 2 )
	{
		printf( "%c", s[j] );
		
		print_palindrome( i, j - 1 );
		
		printf( "%c", s[j] );
	}
	else if ( b[i][j] == 3 )
	{
		printf( "%c", s[i] );
		
		print_palindrome( i + 1, j );
		
		printf( "%c", s[i] );
	}
}

void main()
{
	int i, j, k, l, n, t;
	
	//freopen( "a.in", "r", stdin );
			
	s[0] = '?';
	
	while ( scanf( "%s", s + 1 ) != EOF )
	{				
		n = strlen( s ) - 1;		
		
		for ( l = 2; l <= n; ++l )
		{
			for ( i = 1; i <= n - l + 1; ++i )
			{
				j = i + l - 1;
				
				if ( s[i] == s[j] )
				{
					a[i][j] = a[i + 1][j - 1];
					b[i][j] = 1;
				}
				else
				{
					if ( a[i][j - 1] < a[i + 1][j] )
					{
						a[i][j] = a[i][j - 1] + 1;
						b[i][j] = 2;
					}
					else
					{
						a[i][j] = a[i + 1][j] + 1;
						b[i][j] = 3;
					}
				}				
			}
		}
		
		printf( "%d ", a[1][n] ) ;
		
		print_palindrome( 1, n );
		
		printf( "\n" );
	}
}