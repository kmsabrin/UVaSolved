#include <stdio.h>
#include <string.h>

#define MAX 120

char X[MAX][35], Y[MAX][35];
char tmp[35];
int c[MAX][MAX], b[MAX][MAX];
int m, n;
int i, j;
int flg;

int lcs_length()
{
	memset( c, 0, sizeof( c ) );
	memset( b, 0, sizeof( 0 ) );

	for ( i = 1; i <= m; ++i )
	{
		for ( j = 1; j <= n; ++j )
		{
			if ( strcmp( X[i], Y[j] ) == 0 )
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1; // north west
			}
			else if ( c[i - 1][j] >= c[i][j - 1] )
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2; // north
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3; // west
			}
		}
	}

	return c[m][n];
}

void print_lcs( int i, int j )
{
	if ( i == 0 || j == 0 )
	{
		return;
	}

	if ( b[i][j] == 1 )
	{
		print_lcs( i - 1, j - 1 );

		if ( flg )
		{
			printf( "%s", X[i] );
			flg = 0;
		}
		else
		{
			printf( " %s", X[i] );
		}
	}
	else if ( b[i][j] == 2 )
	{
		print_lcs( i - 1, j );
	}
	else
	{
		print_lcs( i, j - 1 );
	}
}

int main()
{
	//freopen( "a.in", "r", stdin );

	while( 1 )
	{
		i = 1;
		if ( scanf( "%s", tmp ) == EOF )
		{
			break;
		}
		strcpy( X[i++], tmp );

		while ( scanf( "%s", tmp ) && tmp[0] != '#' )
		{
			strcpy( X[i++], tmp );
		}
		m = i - 1;

		j = 1;
		while ( scanf( "%s", tmp ) && tmp[0] != '#' )
		{
			strcpy( Y[j++], tmp );
		}
		n = j - 1;

		lcs_length();

		flg = 1;
	
		print_lcs( m, n );

		printf("\n");
	}

	return 0;
}
