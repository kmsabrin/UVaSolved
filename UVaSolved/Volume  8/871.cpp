#include <stdio.h>
#include <string.h>

char a[30][30];
int row, col;
int cnt;

void call( int i, int j )
{

	if ( i < 0 || i >= row || j < 0 || j >= col || a[i][j] == '0' )
	{
		return;
	}

	++cnt;
	a[i][j] = '0';

	call( i + 1, j - 1 );
	call( i - 1, j - 1 );
	call( i, j - 1 );

	call( i - 1, j );
	call( i + 1, j );

	call( i + 1, j + 1 );
	call( i - 1, j + 1 );
	call( i, j + 1 );
	

}

int main()
{
	int tc, i, j, max;
	char str[30];

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &tc );

	while ( tc-- )
	{

		i = 0;

		while( gets( str ) && str[0] != NULL )
		{
			strcpy( a[i++], str );
		}

		row = i; 
		col = strlen( a[0] );

		
		max = 0;

		for ( i = 0; i < row; ++i )
		{
			for ( j = 0; j < col; ++j )
			{
				if ( a[i][j] == '1' )
				{
					cnt = 0;

					call( i, j );

					if ( cnt > max )
					{
						max = cnt;
					}
				}
			}
		}

		printf( "%d\n", max );

		if ( tc )
		{
			printf( "\n" );
		}
	}

	return 0;
}