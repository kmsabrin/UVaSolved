#include <stdio.h>

void main()
{
	int a[40];
	int i, m, n;

	a[0] = 1;
	a[1] = 2;

	i = 2;

	while ( 1 )
	{		 
		a[i] = a[i - 1] + a[i - 2];

		if ( a[i] > 100000000 )
		{
			break;
		}
		
		++i;
	}

	int t;

	scanf( "%d", &t );
	
	while ( t-- )
	{
		scanf( "%d", &n );

		m = n;

		i = 0;

		while ( a[i] <= n )
		{
			++i;
		}

		--i;

		printf( "%d = ", m );

		while ( i >= 0 )
		{
			if ( n >= a[i] )
			{
				printf( "1" );
				n -= a[i];
			}
			else
			{
				printf( "0" );
			}

			--i;
		}

		printf( " (fib)\n" );
	}
}