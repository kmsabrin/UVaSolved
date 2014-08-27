#include <stdio.h>

void main()
{
	int i, j, k, n, m, t, T;
	
	scanf( "%d", &T );

	while ( T-- )
	{		
		scanf( "%d", &n );

		scanf( "%d", &k );
		
		m = -200000;
		
		for ( i = 1; i < n; ++i )
		{
			scanf( "%d", &j );
									
			t = k - j;
			
			if ( t > m )
			{
				m = t;
			}

			if ( j > k )
			{
				k = j;				
			}
		}
		
		printf( "%d\n", m );
	}
}





