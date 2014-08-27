#include <stdio.h>
#include <math.h>

void main()
{
	long long n, d;
	double x, y, z;

	while ( scanf( "%lld %lld", &n, &d ) != EOF )
	{
		x = 2.0 * n + 1.0;

		y = 2.0 * ( n - d );

		z = ceil( ( -x + sqrt( x * x - 4.0 * y ) ) / 2.0 );

		printf( "%.0lf\n", z + n );
	}
}