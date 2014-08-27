#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXNUM 1000000
#define MAXP   100000

char p[MAXNUM + 10];
int prime[MAXP + 10];

int pFact[1000][2]; 
int nFact;

int maxP[MAXNUM + 10];
int r[MAXNUM + 10];

int min( int a, int b )
{
	if ( a < b )
	{
		return a;
	}

	return b;
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
	int i, j, k, f;

	sieve();	

	r[1] = 1;

	memset( maxP, 0, sizeof( maxP ) );

	for ( i = 2; i <= MAXNUM; ++i )
	{
		k = r[i - 1];

		primeFactors( i );

		for ( j = f = 0; j < nFact; ++j )
		{
			if ( pFact[j][1] > maxP[pFact[j][0]] )
			{
				maxP[pFact[j][0]] = pFact[j][1];

				if ( pFact[j][0] != 5 )
				{
					k = ( k * pFact[j][0] ) % 10;
				}
				else
				{
					f = 1;
				}
			}
		}

		if ( f )
		{
			int t = min( maxP[2], maxP[5] );

			k = (int)pow( 2, (double)( maxP[2] - t ) ) % 10;			

			for ( j = 3; j <= i; j += 2 )
			{
				if ( maxP[j] )
				{
					if ( j == 5 )
					{
						if ( maxP[j] - t > 0 )
						{						
							k = ( k * ( (int)pow( j % 100, (double)( maxP[j] - t ) ) % 10 ) ) % 10;						
						}
					}
					else
					{						
						k = ( k * ( (int)pow( j % 100, (double)maxP[j] ) % 10 ) ) % 10;
					}										
				}
			}
		}
	
		r[i] = k;
	}

	//freopen( "a.in", "r", stdin ) ;

	while ( scanf( "%d", &i ) && i )
	{
		printf( "%d\n", r[i] );
	}	
}