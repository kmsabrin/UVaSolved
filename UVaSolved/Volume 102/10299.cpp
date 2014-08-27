#include <stdio.h>
#include <string.h>

#define MAXNUM 40000
#define MAXP   4000

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

// pFactor[][0] = factor, pFactor[][1] = no. of occurances of that factor
int pFact[1000][2]; 
int nFact; // no. of distinct factors

void primeFactors( int num )
{
	nFact = 0;

	for ( int i = 0; prime[i] * prime[i] <= num && prime[i] != -1 && num > 1; ++i )
	{
		if ( num % prime[i] == 0 )
		{
			pFact[nFact][0] = prime[i];	

			int n = 0;

			while ( num % prime[i] == 0 )
			{
				num /= prime[i];
				++n;
			}

			pFact[nFact][1] = n;	
			++nFact;
		}
	}

	if ( num > 1 )
	{
		pFact[nFact][0] = num;	
		pFact[nFact][1] = 1;	
		++nFact;
	}
}

void main()
{
	int n, i;

	sieve();

	while ( scanf( "%d", &n ) && n )
	{
		if ( n == 1 )
		{
			printf( "0\n" );
			continue;
		}

		primeFactors( n );

		for ( i = 0; i < nFact; ++i )
		{
			n = ( n / pFact[i][0] ) * ( pFact[i][0] - 1 );
		}

		printf( "%d\n", n );
	}
}