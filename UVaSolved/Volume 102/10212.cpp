#include <math.h>
#include <stdio.h>

void main()
{
	int i, j, k, m, n, r;

	while ( scanf( "%d %d", &n, &r ) != EOF )
	{				
		for ( i = n, k = 0, m = 1; i > n - r; --i )
		{
			j = i;
			
			while ( j % 10 == 0 )
			{
				j /= 10;
			}
			
			while ( ( j & 1 ) == 0 )
			{
				j >>= 1;
				++k;
			}
			
			while ( j % 5 == 0 )
			{
				j /= 5;
				--k;
			}
			
			m = ( m * j ) % 10; 				
		}
								
		if ( k < 0 )
		{
			k = -k % 4 ? -k % 4: 4;			
			m = ( m * (int)pow( 5.0, k ) ) % 10;		
		}		
		else if ( k > 0 )
		{				
			k = k % 4 ? k % 4: 4;			
			m = ( m * (int)pow( 2.0, k ) ) % 10;		
		}
				
		printf( "%d\n", m );
	}
}