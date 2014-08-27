#include <stdio.h>

#define MAXNUM 30000010

#define MAXP   3000000

char p[MAXNUM + 1];  

int prime[MAXP + 1]; 

void sieve()
{
	int i, j;
	
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
	
	for ( i = 3, j = 0; i <= MAXNUM; i += 2 )
	{
		if ( p[i] == 0 )
		{
			prime[j++] = i;
		}
	}

	prime[j] = -1;
}

void primeFactors( long long num )
{
	int ans = 1;

	while ( num % 2 == 0 )
	{
		num /= 2;
	}
	
	for ( int i = 0; prime[i] * prime[i] <= num && prime[i] != -1 && num > 1; ++i )
	{
		if ( num % prime[i] == 0 )
		{	
			int n = 0;

			while ( num % prime[i] == 0 )
			{
				num /= prime[i];
				++n;
			}
			
			ans *= ( n + 1 );
		}
	}

	if ( num > 1 )
	{
		ans += ans;
	}

	printf( "%d\n", ans );
}

void main()
{
	sieve();

	long long n;

	while ( scanf( "%lld", &n ) != EOF )
	{
		primeFactors( n );
	}
}