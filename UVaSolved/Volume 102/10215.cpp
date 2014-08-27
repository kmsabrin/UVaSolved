#include <stdio.h>
#include <math.h>

#define EPS 0.00000001

double minimum( double L, double W )
{
	if ( L < W )
	{
		return L;
	}

	return W;
}

int main()
{
	double L, W, maxX, minX, zero = 0.0;

	while ( scanf( "%lf %lf", &L, &W ) != EOF )
	{
		maxX = ( L + W  - sqrt( L * L + W * W - L * W ) ) / 6.0;

		minX = minimum( L, W ) * 0.5;

		printf( "%.3lf %.3lf %.3lf\n", maxX + EPS, zero, minX + EPS );
	}

	return 0;
}

