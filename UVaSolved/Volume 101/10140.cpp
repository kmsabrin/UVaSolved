// NUMBER THEORY

#include <stdio.h>
#include <string.h>

char p[50000];
char tmp[1000000 + 5];

void primes()
{
	int i, j;
	memset( p, 1, sizeof( p ) );
	p[0] = p[1] = 0;
	for ( i = 2; i * i < 50000; ++i )
		if ( p[i] )
			for ( j = i * i; j < 50000; j += i )
				p[j] = 0;
			return;
}

int main()
{
	unsigned long l, u, index, i, j, k, t;
	unsigned long min, max, minu, minl, maxl, maxu, dist, pre;
	primes();
	
	while( scanf( "%lu %lu", &l, &u ) != EOF ) {
		
		memset( tmp, 1, sizeof( tmp ) );
		if ( l == 1 ) tmp[0] = 0;
		for ( i = 2; i * i <= u; ++i )
			if ( p[i] )
			{
				if ( l > i )
				{
					if ( l % i == 0 )
						index = 0;
					else
					{
						t = l / i;
						index = t * i + i - l;
					}
				}
				else
					index = i * i - l;
				for ( ; index <= u - l; index += i )
					tmp[index] = 0;
			}
			
			max = 0; min = 10000000;
			for ( i = t = 0; i <= u - l; ++i )
				if ( tmp[i] )
				{
					if ( t )
					{
						dist = i - pre;
						if ( dist < min )
						{
							min = dist;
							minl = pre + l; minu = i + l;
						}
						if ( dist > max )
						{
							max = dist;
							maxl = pre + l; maxu = i + l;
						}
					}
					t = 1;
					pre = i;
				}
				if ( max == 0 )
					printf( "There are no adjacent primes.\n" );
				else
					printf( "%lu,%lu are closest, %lu,%lu are most distant.\n", minl, minu, maxl, maxu );
				
	}
	return 0;
}


