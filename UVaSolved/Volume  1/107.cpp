#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long i, j, k;
	unsigned long a, b;
	unsigned long n;
	unsigned long p, q;
	double r, s;

	while ( scanf( "%lu %lu", &p, &q ) && p && q )
	{
		if ( q == 1 )
		{
			a = ( log( (double)p ) / log( 2.0 ) ) + 0.10;

			for ( k = 1, j = 0; k <= p; )			
			{
				j += k;
				k *= 2;
			}
			b = j;
		}
		else
		{		
			
			r = log( (double)q ) / log ( (double)p );

			for ( i = 1;	; ++i )
			{
				s = log( (double)i ) / log( (double)( i + 1 ) );			

				if ( fabs( s - r ) < 0.0000001 )
					break;
			}
			n = i;
			
			for ( j = 0, k = 1; k != q; )
			{
				j += k;
				k *= n;
			}
			a = j;

			for ( i = q, j = 0, k = 1;	i; i /= n )
			{
				j += ( k * i );			
				k *= ( n + 1 );
			}
			b = j;
		}

		printf( "%lu %lu\n", a, b );

	}
	
	return 0;
}
