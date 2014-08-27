#include <stdio.h>
#include <string.h>

#define MAXNUM 48000
#define MAXP   5000

char p[MAXNUM + 10];
int prime[MAXP + 10];

int pFact[5000][2];
int nFact;

int pF[111][111];

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
	int i, j;
	unsigned long long s;
	int n, d;
	int f;
	int tmp[111];
	
	sieve();
	
	memset( pF, 0, sizeof( pF ) );
	
	for ( i = 2; i <= 100; ++i )
	{
		primeFactors( i );

		memcpy( pF[i], pF[i - 1], sizeof( pF[0] ) );
		
		for ( j = 0; j < nFact; ++j )
		{
			pF[i][pFact[j][0]] = pF[i - 1][pFact[j][0]] + pFact[j][1];
		}		
	}
		
	while ( scanf( "%d %d", &n, &d ) && ( n || d ) )
	{
		if ( d < 0 )
		{
			d *= -1;
		}
		
		if ( n <= 1 && d < 2 )
		{
			printf( "1\n" );
			continue;
		}
		
		if ( n <= 1 && d > 1 )
		{
			printf( "0\n" );
			continue;
		}
		
		memcpy( tmp, pF[n], sizeof( pF[0] ) );

		if ( d < 2 )
		{
			for ( i = 2, s = 1; i <= n; ++i )
			{
				if ( tmp[i] )
				{
					s *= ( tmp[i] + 1 );
				}
			}
			
			printf( "%llu\n", s );
			
			continue;
		}
		
		primeFactors( d );
		
		for ( i = 0, f = 1; i < nFact; ++i )
		{	
			if ( pFact[i][0] > n )
			{
				f = 0;
				break;
			}
			else if ( tmp[pFact[i][0]] < pFact[i][1] )
			{
				f = 0;
				break;
			}
			else
			{
				tmp[pFact[i][0]] = tmp[pFact[i][0]] - pFact[i][1] ;
			}
		}
		
		if ( !f )
		{
			printf( "0\n" );
			continue;
		}
		
		for ( i = 2, s = 1; i <= n; ++i )
		{
			if ( tmp[i] )
			{								
				s *= ( tmp[i] + 1 );
			}
		}
		
		printf( "%llu\n", s );
	}	
	
}

