#include <stdio.h>
#include <string.h>

#define MAXNUM 46340

int pFact[5000][2]; 

char p[MAXNUM + 10];

int prime[MAXNUM + 10];

void sieve()
{
	int i, j;

	memset( p, 0, sizeof( p ) );
	p[0] = p[1] = 1;

	for ( i = 2; i * i < MAXNUM; ++i )	
	{
		if ( !prime[i] )		
		{
			for ( j = i * i; j < MAXNUM; j += i )		
			{
				prime[j] = 1;
			}
		}
	}

	for ( i = 2, j = 0; i < MAXNUM; ++i )
	{
		if( !p[i] )
		{
			prime[j++] = i;
		}
	}

	prime[j] = -1;
}

int primeFactors( int num )
{
	int i, n, nF;

	for ( i = nF = 0; prime[i] * prime[i] <= num && prime[i] != -1 && num > 1; ++i )
	{
		if ( num % prime[i] == 0 )
		{
			pFact[nF][0] = prime[i];	
			n = 0;

			while ( num % prime[i] == 0 )
			{
				num /= prime[i];
				++n;
			}

			pFact[nF][1] = n;	
			++nF;
		}
	}

	if ( num > 1 )
	{
		pFact[nF][0] = num;	
		pFact[nF][1] = 1;	
		++nF;
	}

	return nF;
}

void main()
{
	unsigned long long i, j, k, n, nFact;

	sieve();

	while ( scanf( "%llu", &n ) != EOF )
	{
		nFact = primeFactors( n );
		
		j = n;

		k = 1;

		for ( i = 0; i < nFact; ++i )
		{
			j = ( j  / pFact[i][0] ) * ( pFact[i][0] - 1 );			

			k *= ( pFact[i][1] + 1 );			
		}
	
		printf( "%llu\n", n - j + 1 - k );
	}
}
