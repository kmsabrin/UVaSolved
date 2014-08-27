#include <stdio.h>

#define MAXNUM 500050
#define MAXP   42000

char p[MAXNUM + 10];
char c[2 * MAXNUM + 10];
int prime[MAXP + 10];

void sieve()
{
	int i, j;

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

void generate()
{
	int i, j, k;

	for ( i = 0; prime[i] <= 1000; ++i )
	{
		k = prime[i];

		for ( j = i; k * prime[j] <= 1000000; ++j )
		{
			c[k * prime[j]] = 1;
		}
	}
}

void main()
{
	int i, j, k, n;
	
	sieve();

	generate();
	
	while ( scanf( "%d", &n ) != EOF )
	{
		for ( i = k = 0; i < n; ++i )
		{
			scanf( "%d", &j );
			
			if ( c[j] )
			{
				++k;				
			}
		}
		
		printf( "%d\n", k );
	}		
}