#include <stdio.h>
#include <string.h>

char road[21][21], war[21][21], used[21];

int path[21], count, t, n, index;

int call( int s )
{
	int i;

	path[index++] = s;
	used[s] = 1;

	if ( s == t )
	{
		printf( "%d", path[0] );
		for ( i = 1; i < index; ++i )
			printf( " %d", path[i] );
		printf( "\n" );
		++count;		
	}
	else
	{
		for ( i = 1; i <= n; ++i )
			if ( !used[i] && road[s][i] && war[s][t] )
				call( i );
	}

	used[s] = 0;
	index--;

	return 0;
}


int main()
{
	int i, j, k, c = 0;

	while ( scanf( "%d", &t ) != EOF )
	{

		printf( "CASE %d:\n" , ++c	);

		memset( road, 0, sizeof( road ) );
		memset( war,  0, sizeof( war ) );
		memset( used, 0, sizeof( used ) );

		n = 0;
		while ( 1 )
		{
			scanf( "%d %d", &j, &k );

			if ( !j && !k )
				break;

			road[j][k] = road[k][j] = 1;
			war[j][k] = war[k][j] = 1;

			if ( j > n )
				n = j;
			if ( k > n )
				n = k;
		}

		for ( k = 1; k <= n; ++k )
			for ( i = 1; i <= n; ++i )
				for ( j = 1; j <= n; ++j )
					war[i][j] = war[i][j] || ( war[i][k] && war[k][j] );

		index = count = 0;

		call( 1 );

		printf( "There are %d routes from the firestation to streetcorner %d.\n", count, t );

	}

	return 0;
}