#include <stdio.h>
#include <string.h>

int a[101][101], b[101][101], c[101];
int size;

int aa( int n, int m )
{
	int i;

	for ( i = 0; i < size; ++i )
	{
		if ( a[n][i] == 1 && b[m][i] == 0 )
		{
			b[m][i] = 1;
			aa( i, m );
		}
	}

	return 0;
}

int bb()
{
	int i, j;

	for ( i = 0; i < size; ++i )
		for ( j = 0; j < size; ++j )
			if ( b[i][j] )
				++c[i];

	return 0;
}



int cc()
{
	int l = c[0];
	int k = 0;
	int i;

	for ( i = 1; i < size; ++i )
	{
		if ( c[i] > l )
		{
			l = c[i];
			k = i;
		}
	}

	return k + 1;
}

int main()
{
	int i, j, k, d;

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &size ) && size )
	{
		memset( a, 0, sizeof ( a ) );
		memset( b, 0, sizeof ( b ) );
		memset( c, 0, sizeof ( c ) );

		for ( i = 0; i < size; ++i )
		{
			scanf( "%d", &d );
			for ( j = 0; j < d; ++j )
			{
				scanf( "%d", &k );
				a[i][k - 1] = 1;
			}
		}

		for ( i = 0; i < size; ++i )
			aa( i, i );

		bb(); 

		printf( "%d\n", cc() );

	}

	return 0;
}



