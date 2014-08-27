#include <stdio.h>
#include <math.h>

void main()
{
	int f, L;

	double v, V;

	while ( scanf( "%d %d", &L, &f ) )
	{
		if ( !f && !L )
		{
			break;
		}

		v = sqrt( 2.0 * f * L );

		V = ( 7200 * v * f ) / ( v * v + 2 * f * L );		

		printf( "%.8lf %.8lf\n", v, V );
	}
}