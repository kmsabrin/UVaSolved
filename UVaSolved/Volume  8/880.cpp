#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long a, b, m, n, s, d;
	
	while ( scanf( "%llu", &m ) != EOF )
	{

		a = 1 + ( 8 * m );

		b = ( unsigned long long )sqrt( ( double )a );
	
		n = ( b - 1 ) / 2;

		if ( ( b * b ) != a )
		{
			n = n + 1;
		}

		s = ( ( n * ( n - 1 ) ) / 2 ) + 1;

		d = m - s;

		printf( "%llu/%llu\n", n - d, d + 1 );

	}

	return 0;
}