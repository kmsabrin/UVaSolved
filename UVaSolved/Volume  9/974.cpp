#include <stdio.h>

char kap[40000 + 1];

void main()
{
	int n, m, k, i, f, c = 0;

	for ( n = 2; n <= 40000; ++n )
	{
		m = n * n;

		k = 10;

		while ( 1 ) 
		{
			if ( m / k == 0 )
			{
				break;
			}

			if ( ( m / k ) + ( m % k ) == n )
			{
				if ( ( m / k ) && ( m % k ) )
				{
					kap[n] = 1;					
					break;
				}
			}

			k *= 10;
		}
	}

	scanf( "%d", &n );

	while ( n-- )
	{
		scanf( "%d %d", &m, &k );

		f = 0;

		printf( "case #%d\n", ++c );

		for ( i = m; i <= k; ++i )
		{
			if ( kap[i] )
			{
				printf( "%d\n", i );
				f = 1;
			}
		}

		if ( !f )
		{
			printf( "no kaprekar numbers\n" );
		}

		if ( n )
		{
			printf( "\n" );
		}
	}
}