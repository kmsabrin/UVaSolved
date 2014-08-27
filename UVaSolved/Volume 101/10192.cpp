// LONGEST COMMON SUBSEQUENCE

#include <stdio.h>
#include <string.h>

#define MAX 110

char X[MAX], Y[MAX]; // input string are X and Y
int m, n; // string length of X and Y are m and n
int c[MAX][MAX]; // c is the lcs length table
int i, j; // counters

int lcs_length()
{
	m = strlen( X );
	n = strlen( Y );
	
	memset( c, 0, sizeof( c ) );
	
	for ( i = 1; i <= m; ++i )
	{
		for ( j = 1; j <= n; ++j )
		{
			if ( X[i - 1] == Y[j - 1] )
			{
				c[i][j] = c[i - 1][j - 1] + 1;			
			}
			else if ( c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
	
	return c[m][n];
}

int main()
{
	int tc = 1;
	
	while ( 1 )
	{
		gets( X );
		
		if ( X[0] == '#' )
		{
			break;
		}
		
		gets( Y );
		printf( "Case #%d: you can visit at most %d cities.\n", tc++, lcs_length() );
	}
	
	return 0;
}

