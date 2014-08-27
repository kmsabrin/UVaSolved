#include <stdio.h>

void main()
{
	double a1, a2, b1, b2, c1, c2, x, y;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%lf %lf %lf", &a1, &b1, &c1 );
		scanf( "%lf %lf %lf", &a2, &b2, &c2 );

		if ( !a1 && !a2 && !b1 && !b2 && !c1 && !c2 )
		{
			break;
		}

		if ( a1 / b1 == a2 / b2 )
		{
			printf( "No fixed point exists.\n");
		}
		else
		{
			x = ( c1 * b2 - c2 * b1 ) / ( a1 * b2 - a2 * b1 );
			y = ( a1 * c2 - a2 * c1 ) / ( a1 * b2 - a2 * b1 );
			printf( "The fixed point is at %.2lf %.2lf.\n", x,  y );
		}
	}
}