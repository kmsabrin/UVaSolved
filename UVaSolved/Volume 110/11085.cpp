#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char r[9];
char s[92][9]; 
char t[9];
int cnt;

int place( int k, int i )
{
	for ( int j = 1; j <= k - 1; ++j )
	{
		if ( r[j] == i || abs( r[j] - i ) == abs( j - k ) )
		{
			return 0;
		}
	}

	return 1;
}

void n_queens( int k, int n )
{
	for ( int i = 1; i <= n; ++i )
	{
		if ( place( k, i ) )
		{
			r[k] = i;

			if ( k == n )
			{
				strcpy( s[cnt++], r );				
			}
			else
			{
				n_queens( k + 1, n );
			}
		}
	}
}

void main()
{	
	cnt = 0;

	r[0] = 'x';

	n_queens( 1, 8 );

	int i, j;	
	int c =0 ;
	int min;
	int sum;
	
	while ( scanf( "%d", &i ) != EOF )
	{
		t[1] = i;

		for ( i = 2; i <= 8; ++i )
		{
			scanf( "%d", &t[i] );
		}

		min = 10;

		for ( i = 0; i < cnt; ++i )
		{
			sum = 0;

			for ( j = 1; j <= 8; ++j )
			{
				if ( t[j] != s[i][j] )
				{
					++sum;
				}
			}

			if ( sum < min )
			{
				min = sum;
			}
		}

		printf( "Case %d: %d\n", ++c, min );
	}
}