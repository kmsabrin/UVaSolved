#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXSIEVE 100000000
#define MAXSIEVEHALF ( MAXSIEVE / 2 )
#define MAXSQRT 5000
#define isprime( n ) ( a[n >> 4] & ( 1 << ( ( n >> 1 ) & 7 ) ) )

char a[MAXSIEVE / 16];

void sieve()
{
	int i, j;

	memset( a, -1, sizeof( a ) );
	a[0] = 0xFE;

	for ( i = 1; i < MAXSQRT; ++i )
	{
		if ( a[i >> 3] & ( 1 << ( i & 7 ) ) )
		{
			for( j = i + i + i + 1; j < MAXSIEVEHALF; j += i + i + 1 )
			{
				a[ j >> 3] &= ~( 1 << ( j & 7 ) );
			}
		}
	}
}

int main()
{
	int n, i;

	sieve();

	while ( scanf( "%d", &n ) != EOF )
	{
		if ( n <= 3 )
		{
			printf( "%d is not the sum of two primes!\n", n );
		}
		else if ( n & 1 )
		{
			if ( isprime( n - 2 ) )
			{
				printf( "%d is the sum of 2 and %d.\n", n, n - 2 );
			}
			else
			{
				printf( "%d is not the sum of two primes!\n", n );
			}
		}
		else
		{
			char ok = 0;

			i = n / 2;

			if ( i & 1 )
			{
				i -= 2;
			}
			else
			{
				--i;
			}

			for (	; i > 2; i -= 2 )
			{
				if ( isprime( i ) && isprime( n - i ) )
				{
					printf( "%d is the sum of %d and %d.\n", n, i, n - i );
					ok = 1;
					break;
				}
			}

			if ( !ok )
			{
				printf("%d is not the sum of two primes!\n", n);
			}
		}
	}

	return 0;
}



