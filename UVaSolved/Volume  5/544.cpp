#include <stdio.h>
#include <string.h>

int n, i1, i2, c;

char str[201][31];

int w[201][201]; 

int max( int i, int j )
{
	if ( i > j )
		return i;
	return j;
}

int min( int i, int j )
{
	if ( i < j )
		return i;
	return j;
}

void findIndex( char a[], char b[] )
{
	for ( int i = 0; i < c; ++i )
	{
		if ( !strcmp( str[i], a ) )
			i1 = i;
		if ( !strcmp( str[i], b ) )
			i2 = i;
	}
}

int takeInput()
{
	int m;
	scanf( "%d %d", &n, &m );

	if ( !n )
		return 0;

	int i, j;
	for ( i = 0; i < n; ++i )
		for ( j = 0; j < n; ++j )
			w[i][j] = 0;
	
	int tmp;
	char a[31], b[31];	
	c = 0;
	for ( i = 0; i < m; ++i )
	{		
		scanf( "%s %s %d", a, b, &tmp );
		i1 = i2 = -1;
		findIndex( a, b );

		if ( i1 == -1 )
		{
			i1 = c++;
			strcpy( str[i1], a );
		}

		if ( i2 == -1 )
		{
			i2 = c++;
			strcpy( str[i2], b );
		}		

		w[i1][i2] = w[i2][i1] = tmp;
	}

	return 1;
}

void floydWarshall()
{
	for ( int k = 0; k < n; ++k )
		for ( int i = 0; i < n; ++i )
			for ( int j = 0; j < n; ++j )
					w[i][j] = max( w[i][j], min( w[i][k], w[k][j] ) );

}

void result( int t )
{
	char a[31], b[31];
	scanf( "%s %s", a, b );
	findIndex( a, b );

	printf( "Scenario #%d\n", t );
	printf( "%d tons\n", w[i1][i2] );
	printf( "\n" );
}

void main()
{
	int tcase = 0;

	//freopen ( "in.in", "r", stdin );

	while ( takeInput() )
	{
		floydWarshall();
		result( ++tcase );
	}
}




