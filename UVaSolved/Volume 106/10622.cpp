#include <stdio.h>
#include <string.h>

#define MAXNUM 50000
#define MAXP   5000

char p[MAXNUM + 10];  // prime[i] = 0 iff i is prime
long long prime[MAXP + 10];

int pFact[1000][2]; // pFactor[][0] = factor, pFactor[][1] = no. of occurances of the factor
int nFact; // no. of distinct factors

int max( int a, int b )
{
	if ( a > b )
	{
		return a;
	}

	return b;
}

int gCd ( int a, int b )
{
	if ( !b )	
	{
		return a;	
	}

	return gCd( b, a % b );
}

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

void primeFactors( long long num )
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

int countGCD()
{
	if ( nFact == 0 )
	{
		return 1;
	}

	if ( nFact < 2 )
	{
		return pFact[0][1];
	}

	int k = gCd( pFact[0][1], pFact[1][1] );

	for ( int i = 2; i < nFact; ++i )
	{
		k = gCd( k, pFact[i][1] );
	}

	return k;
}

void main()
{
	long long n;
	int k;

	sieve();

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%lld", &n ) && n )
	{
		if ( n < 0 )
		{
			primeFactors( -n );

			k = countGCD();

			if ( k & 1 )
			{
				printf( "%d\n", k );
			}
			else
			{
				int j = 1;

				for ( int i = 1; i * i <= k; ++i )
				{
					if ( k % i == 0 )
					{
						if ( i & 1 )
						{
							j = max( j, i );
						}

						if ( ( k / i ) & 1 )
						{
							j = max( j, k / i );
						}
					}
				}

				printf( "%d\n", j );
			}
		}
		else
		{
			primeFactors( n );

			k = countGCD();

			printf( "%d\n", k );
		}
	}
}



		
