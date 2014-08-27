#include <stdio.h>
#include <math.h>

int main()
{
	int t, u, v, m, n, r;

	scanf( "%d", &t );
	
	while ( t-- )
	{
		scanf( "%d %d", &u, &v );
		
		m = abs( u - v );

		if ( m <= 2 )
		{
			printf( "%d\n", m );

			continue;
		}
		
		n = (int)ceil( ( ( sqrt( 4.0 * m + 1.0 ) - 1.0 ) / 2.0 ) );
		
		if ( n * n + n - m >= n )
		{
			r = n + n - 1;
		}
		else
		{
			r = n + n;
		}
		
		printf( "%d\n", r );
	}

	return 0;
}