#include <stdio.h>
#include <string.h>

#define MAXNUM 100000
#define MAXP   10000

char p[MAXNUM + 1]; 
int prime[MAXP + 1];

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
				if ( !p[j] )
				{
					p[j] = 1;
				}
			}
		}
	}
	
	prime[0] = 2;
	
	for ( i = 3, j = 1; i <= MAXNUM; i += 2 )
	{
		if ( !p[i] )
		{
			prime[j++] = i;			
		}
	}
	
	prime[j] = -1;	
}

int primeFactors( int num )
{
	if ( !p[num] )
	{
		return num;
	}

	int big_fact;
	int i, j;
	
	for ( i = 0; prime[i] * prime[i] <= num && prime[i] != -1 && num > 1; ++i )
	{
		j = prime[i];

		if ( !( num % j ) )
		{
			big_fact = j;	
						
			while ( !( num % j ) )
			{
				num /= j;			
			}									
		}
	}
	
	if ( num > 1 )
	{
		return num;				
	}
	else
	{
		return big_fact;
	}
}

void main()
{	
	long long n, b, p;
	long long m, r, s;
	long long t;
	
	sieve();
	
	while ( scanf( "%lld %lld", &n, &b ) && b )
	{		
		p = primeFactors( b );				
		
		t = 0;
		
		for ( m = p; n / m; m *= p )
		{
			r = ( n / m - 1 );

			s = ( n % m + 1 );

			t += ( m * r * ( r + 1 ) ) / 2  + s * ( r + 1 );
		}
				
		printf( "%lld\n", t );
	}
}