// NUMBER THEORY

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXNUM 47000
#define MAXP   5000

char p[MAXNUM + 10];
int prime[MAXP + 10];

int pFact[2000][2];
int nFact;

void sieve()
{
	int i, j;

	memset( p, 0, sizeof( p ) );

	p[0] = p[1] = 1;

	for ( i = 2; i * i <= MAXNUM; ++i )
	{
		if ( !p[i] )
		{
			for ( j = i * i; j <= MAXNUM; j += i )
			{
				p[j] = 1;
			}
		}
	}

	for ( i = 2, j = 0; i <= MAXNUM; ++i )
	{
		if ( !p[i] )
		{
			prime[j++] = i;
		}
	}

	prime[j] = -1;
}

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
	int i, n, c = 0;
	unsigned int sum;

	sieve();

	while ( scanf( "%d", &n ) && n )
	{
		primeFactors( n );

		for ( i = sum = 0; i < nFact; ++i )
		{
			sum += (int)pow( pFact[i][0], pFact[i][1] );
		}

		if ( nFact == 1 )
		{
			++sum;
		}

		if ( n == 1 )
		{
			sum = 2;
		}

		printf( "Case %d: %u\n", ++c, sum );
	}
}