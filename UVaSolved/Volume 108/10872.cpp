#include <stdio.h>

int main()
{
	unsigned long long a, b, c = 0, k, m, n, N, p, s;

	while ( scanf( "%llu", &N ) && N )
	{
		a = ( N - 1 ) / 2 ;

		b = ( N / 3 );

		if ( N % 3 )
		{
			++b;
		}

		n = a - b + 1;

		s = N - a;

		p = ( s / 2 ) + 1;

		if( s % 2 == 0 )
		{
			if( n % 2 == 0 )
			{
				m = ( n / 2 ) * ( 2 * p + ( n / 2 ) - 1 );
			}
			else
			{
				m = ( n / 2 ) * ( 2 * p + ( n / 2 ) - 1 ) + p + ( n / 2 );
			}
		}
		else
		{
			if ( n % 2 == 0 )
			{
				m = ( ( n - 2 ) / 2 ) * ( 2 * ( p + 1 ) + ( ( n - 2 ) / 2 ) - 1 ) + p + p + ( n - 2 ) / 2 + 1;
			}
			else
			{
				m = ( n / 2 ) * ( 2 * ( p + 1 ) + ( n / 2 ) - 1 ) + p ;
			}
		}

		if (  s - a == 1 )
		{
			k =   n * ( 2 + 2 * ( n - 1 ) ) / 2;
		}
		else
		{
			k =   n * ( 4 + 2 * ( n - 1 ) ) / 2;
		}

		printf( "Case %llu: %llu\n", ++c, m - k );
	}

	return 0;
}
