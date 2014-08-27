#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, A, B, C, s, area, aA, bB, cC;
	int k;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &k );

	while ( k-- )
	{	
		scanf( "%lf %lf %lf", &a, &b, &c );
	
		aA = a + c;
		bB = a + b;
		cC = b + c;

		C = acos ( ( aA * aA + bB * bB - cC * cC ) / ( 2 * aA * bB ) );
		B = acos ( ( aA * aA + cC * cC - bB * bB ) / ( 2 * aA * cC ) );
		A = acos ( ( cC * cC + bB * bB - aA * aA ) / ( 2 * cC * bB ) );

		s =  a + b + c;
		area = sqrt ( s * ( s - aA ) * ( s - bB ) * ( s - cC ) );		
		area -= ( C * a * a + A * b * b + B * c * c ) / 2.0;

		printf( "%.6lf\n", area );
	}

	return 0;
}
