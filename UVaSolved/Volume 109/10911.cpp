#include <stdio.h>
#include <math.h>

int n;

double min_sum;

int X[16], Y[16];

char used[16];

double distance( int i, int j )
{
	return sqrt( double( ( X[i] - X[j] ) * ( X[i] - X[j] ) + ( Y[i] - Y[j] ) * ( Y[i] - Y[j] ) ) );
}

int call( double sum ) 
{
	int i, j;

	if ( sum > min_sum )
	{
		return 0;
	}

	for ( i = 0; i < n; ++i )
	{
		if ( !used[i] )
		{
			used[i] = 1;
			break;
		}
	}

	if ( i == n )
	{
		if ( sum < min_sum )
		{
			min_sum = sum;
			return 0;
		}
	}

	for ( j = i + 1; j < n; ++j )
	{
		if ( !used[j] )
		{
			used[j] = 1;			

			call( sum + distance( i, j ) );

			used[j] = 0;
		}
	}

	used[i] = 0;

	return 0;
}

int main()
{
	int i;

	char tmp[50];

	int kase = 0;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) && n )
	{		
		n <<= 1;
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%s %d %d", tmp, &X[i], &Y[i] );

			used[i] = 0;
		}	
		
		min_sum = 10e15;
		
		call( 0.0 );
		
		printf( "Case %d: %.2lf\n", ++kase, min_sum );
	}

	return 0;
}