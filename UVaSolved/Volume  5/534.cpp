#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int x[250], y[250];
double w[250][250];

double dist( int i, int j )
{
	 return sqrt( double( ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) ) );
}

double min( double i, double j )
{
	if ( i < j )
		return i;
	return j;
}

double max( double i, double j )
{
	if ( i > j )
		return i;
	return j;
}

int main()
{
	int n;
	int i, j, k;
	int c = 0;

	//freopen( "in.in", "r", stdin );
	
	while ( scanf( "%d", &n ) && n )
	{

		for ( i = 0; i< n; ++i )
			scanf( "%d %d", &x[i], &y[i] );

		for ( i = 0; i < n; ++i )
			for ( j = 0; j < n ; ++j )
				w[i][j] = dist( i, j );


		for ( k = 0; k < n; ++k )
			for ( i = 0; i < n; ++i )
				for ( j = 0; j < n; ++j )
					w[i][j] = min( w[i][j], max( w[i][k], w[k][j] ) );

		printf( "Scenario #%d\n", ++c );
		printf( "Frog Distance = %.3lf\n\n", w[0][1] );

	}

	return 0;

}
