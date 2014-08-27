#include <stdio.h>
#include <string.h>

int n, i1, i2;

char str[40][80];

double arbitrage[40][40]; 

double max( double i, double j )
{
	if ( i > j )
		return i;
	return j;
}

void findIndex( char a[], char b[] )
{
	for ( int i = 0; i < n; ++i )
	{
		if ( !strcmp( str[i], a ) )
			i1 = i;
		if ( !strcmp( str[i], b ) )
			i2 = i;
	}
}

int takeInput()
{

	scanf( "%d", &n );

	if ( !n )
		return 0;
	
	memset( arbitrage, 1000000000, sizeof( arbitrage ) );

	int i;
	for ( i = 0; i < n; ++i )
	{
		scanf( "%s", &str[i] );
		arbitrage[i][i] = 1.0;
	}

	int m;
	scanf( "%d", &m );

	double tmp;
	for ( i = 0; i < m; ++i )
	{
		char a[100], b[100];
		scanf( "%s %lf %s", a, &tmp, b );
		findIndex( a, b );
		arbitrage[i1][i2] = tmp;
	}

	return 1;
}

void floydWarshall()
{
	for ( int k = 0; k < n; ++k )
		for ( int i = 0; i < n; ++i )
			for ( int j = 0; j < n; ++j )
			{
				arbitrage[i][j] = max ( arbitrage[i][j], arbitrage[i][k] * arbitrage[k][j] );
				if ( arbitrage[i][i] > 1 )
					return;
			}
}

void yesNo( int tcase )
{
	printf( "Case %d: ", tcase );

	for ( int i = 0; i < n; ++i )
		if ( arbitrage[i][i] > 1 )
		{
			printf( "Yes\n" );
			return;
		}

	printf( "No\n" );
}

void main()
{
	int tcase = 0;

	while ( takeInput() )
	{
		floydWarshall();
		yesNo( ++tcase );
	}
}




