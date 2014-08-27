#include <stdio.h>

int main()
{
	int a[101][101];
	int flg1, flg2, i, j, sum, row, col, n;

	//freopen ( "a.in", "r", stdin );
	
	while ( 1 )
	{

	scanf( "%d", &n );

	if ( n == 0 )
	{
		break;
	}

	for ( i = 0; i < n; ++i )
	{
		for ( j = 0; j < n; ++j ) 
		{
			scanf( "%d", &a[i][j] );
		}
	}

	row = -1;
	flg1 = 1;

	for ( i = 0; i < n; ++i )
	{
		sum = 0;

		for ( j = 0; j < n; ++j )
		{
			sum += a[i][j];
		}

		if ( sum % 2 )
		{
			if ( row == -1 )
			{
				row = i;
			}
			else
			{
				flg1 = 0;
				break;
			}
		}
	}

	col = -1;
	flg2 = 1;

	for ( i = 0; i < n; ++i )
	{
		sum = 0;

		for ( j = 0; j < n; ++j )
		{
			sum += a[j][i];
		}

		if ( sum % 2 )
		{
			if ( col == -1 )
			{
				col = i;
			}
			else
			{
				flg2 = 0;
				break;
			}
		}
	}

	if ( row == -1 && col == -1 )
	{
		printf( "OK\n" );
	}
	else if ( flg1 == 0 || flg2 == 0 )
	{
		printf( "Corrupt\n" );
	}
	else
	{
		printf( "Change bit (%d,%d)\n", row + 1, col + 1 );
	}

	}

	return 0;
}
