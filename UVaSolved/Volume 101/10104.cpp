// NUMBER THEORY

#include <stdio.h>

int gcd( int p, int q, int *x, int *y ) // EXTENDED EUCLID
{
	int x1, y1, g;
	
	if ( q > p )
		return gcd( q, p, y, x ); // INTERESTING
	
	if ( q == 0 ) // BASE CASE
	{
		*x = 1;
		*y = 0;
		return p;
	}
	
	g = gcd( q, p % q, &x1, &y1 );
	*x = y1;
	*y = x1 - ( p / q ) * y1;
	
	return g;
}

int main()
{
	int a, b, g, x, y;
	while( scanf( "%d %d", &a, &b ) != EOF )
	{
		g = gcd( a, b, &x, &y );
		/*	
		while ( x > y )
		{
		x -= b / g;
		y += a / g;
		} 
		*/
		printf( "%d %d %d\n", x, y, g );
	}
	return 0;
}