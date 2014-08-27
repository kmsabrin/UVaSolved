#include <stdio.h>
#include <string.h>

#define MAXNUM 1000000 + 100
#define MAXP   100000 + 100

char p[MAXNUM + 10];  // prime[i] = 0 iff i is prime
int prime[MAXP + 10]; // contains primes, ends with a -1

void sieve()
{
	int i, j;

	memset( p, 0, sizeof( p ) );

	p[0] = p[1] = 1;

	for ( i = 2; i * i <= MAXNUM; ++i )
	{
		if ( p[i] == 0 )
		{
			for ( j = i * i; j <= MAXNUM; j += i )
			{
				if ( p[j] == 0 )
				{
					p[j] = 1;
				}
			}
		}
	}

	prime[0] = 2;

	for ( i = 3, j = 1; i <= MAXNUM; i += 2 )
	{
		if ( p[i] == 0 )
		{
			prime[j++] = i;
		}
	}

	prime[j] = -1;
}

void main()
{
	int i, l, u, d, max, cnt, champ, T;

	int flg[121];

	sieve();

	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d %d", &l, &u );

		i = 0;
		
		while ( prime[i] < l )
		{
			++i;
		}

		max = 0;

		memset( flg, 0, sizeof( flg ) );

		++i;	

		while ( prime[i] <= u )
		{			
			d = prime[i] - prime[i - 1];
			
			++flg[d];

			if ( flg[d] > max )
			{
				max = flg[d];
				champ = d;
			}

			++i;
		}
		
		if ( max == 0 )
		{
			printf( "No jumping champion\n" );
		}
		else
		{
			for ( i = cnt = 0; i <= 120; ++i )
			{
				if ( flg[i] == max )
				{
					++cnt;
				}

				if ( cnt > 1 )
				{
					break;
				}
			}

			if ( cnt == 1 )
			{
				printf( "The jumping champion is %d\n", champ );
			}
			else
			{
				printf( "No jumping champion\n" );
			}
		}
	}
}