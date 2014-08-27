#include <stdio.h>
#include <math.h>

double dist( double x, double y, double p, double q )
{
	return sqrt( ( x - p ) * ( x - p ) + ( y - q ) * ( y - q ) );
}

int main()
{
	int f = 0, n, i, k;
	double dx, dy, gx, gy, tx, ty, dlen, glen;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
	
		if ( scanf( "%d", &n ) == EOF )
			break;
		scanf( "%lf %lf %lf %lf", &gx, &gy, &dx, &dy );

		for ( i = k = 0; i < n; ++i )
		{
			scanf( "%lf %lf", &tx, &ty );

			if ( k ) 
				continue;

			dlen = dist( dx, dy, tx, ty );
			glen = dist( gx, gy, tx, ty );

			if ( 2 * glen > dlen )
			//if ( 2 * glen - dlen > 0.0001 )
				;
			else
			{
				k = 1;
				printf( "The gopher can escape through the hole at (%.3lf,%.3lf).\n", tx, ty );
			}
		}

		if ( !k )
			printf( "The gopher cannot escape.\n" );

		
	}

	return 0;
}

