#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, theta;

	double A, B, C, R, r, d, s;

	double pi = acos( -1.0 );

	while ( scanf( "%lf %lf %lf", &a, &b, &c ) != EOF )
	{		
		theta = acos( ( b * b + c * c - a * a ) / ( 2.0 * b * c ) );

		R = a / ( 2.0 * sin( theta ) );

		s = ( a + b + c ) / 2.0;
		
		d = sqrt( s * ( s - a ) * (s - b ) * ( s - c ) );
		
		A = pi * R * R - d;
		
		r = ( 2.0 * d ) / ( a + b + c );
		
		C = pi * r * r;
		
		B = d - C;
		
		printf( "%.4lf %.4lf %.4lf\n", A, B, C );
	}

	return 0;
}


