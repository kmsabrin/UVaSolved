#include <stdio.h>
#include <string.h>

#define MAXNUM 1000000

char p[MAXNUM + 1];

int cp[MAXNUM + 1];

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
}

void main()
{
	int i, j, k, l, u, f;
	
	int limit[] = { 10, 100, 1000, 10000, 100000 };
	int until[] = { 99, 999, 9999, 99999, 999999 };
	
	sieve();
		
	memset( cp, -1, sizeof( cp ) );

	for ( i = 1, j = 100; i < 5; ++i )
	{
		l = limit[i];
		
		for (  ; j <= until[i]; ++j )
		{
			if ( cp[j] == 1 || cp[j] == 0 )
			{
				continue;
			}
			else 
			{
				if ( !p[j] )
				{
					f = 1;
					
					k = ( j % l ) * 10 + ( j / l );
					
					if ( k > until[i - 1] && p[k] )
					{
						f = 0;					
					}
					
					while ( f && k != j )
					{
						k = ( k % l ) * 10 + ( k / l );
						
						if ( k > until[i - 1] && p[k] )
						{
							f = 0;						
						}
					}
				}
				else
				{
					f = 0;
				}
												
				cp[j] = f;
					
				k = ( j % l ) * 10 + ( j / l );
					
				if ( k > until[i - 1] )
				{
					cp[k] = f;
				}
					
				while ( k != j )
				{
					k = ( k % l ) * 10 + ( k / l );
					
					if ( k > until[i - 1] )
					{
						cp[k] = f;
					}							
				}								
			}
		}
	}
	
	cp[99] = 0;

	for ( i = 100; i < 1000000; ++i )
	{
		cp[i] += cp[i - 1];				
	}

	while ( scanf( "%d", &l ) && l != -1 )
	{
		scanf( "%d", &u );		

		k = cp[u] - cp[l - 1];

		if ( !k )
		{
			printf( "No " );
		}
		else
		{
			printf( "%d ", k );
		}

		if ( !k || k > 1 )
		{
			printf( "Circular Primes.\n" );
		}
		else
		{
			printf( "Circular Prime.\n" );
		}

	}	
}




