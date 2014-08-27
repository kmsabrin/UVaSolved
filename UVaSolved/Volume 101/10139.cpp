// NUMBER THEORY

#include <stdio.h>
#include <string.h>
#define MAX 50000

int main()
{
	char prime[MAX];
	long long i, j, k, u, v, p, r, flg, f2, m, n;
	
	memset( prime, 1, sizeof( char ) * MAX );
	for ( i = 2; i * i < MAX; ++i )
		if ( prime[i] )
			for ( j = i * i; j < MAX; j += i )
				prime[j] = 0;
			
			while( scanf( "%lld %lld", &n, &m ) != EOF )
			{
				if ( m == 1 )
				{
					printf( "%lld divides %lld!\n", m, n );
					continue;
				}
				if ( m == 0 )
				{
					printf( "%lld does not divide %lld!\n", m, n );
					continue;
				}
				if ( n == 0 )
				{
					printf( "%lld does not divide %lld!\n", m, n );
					continue;
				}
				if ( n == 1 )
				{
					printf( "%lld does not divide %lld!\n", m, n );
					continue;
				}
				if ( n >= m )
				{
					printf( "%lld divides %lld!\n", m, n );
					continue;
				}
				v = m;
				flg = 1;
				f2 = 0;
				for ( i = 2; v != 1 && i * i <= m; ++i )
					if ( prime[i] )
						if ( ( v % i ) == 0 )
						{
							f2 = 1; // so that not a prime
							k = 0;
							while ( ( v % i ) == 0 )
							{
								v /= i;
								++k;
							}
							u = n;
							p = i;
							r = 0;
							while ( u / p )
							{
								r += u / p;
								p *= i;
							}
							// printf( "%d %d %d\n", i, k, r );
							if ( r < k )
							{
								flg = 0;
								break;
							}
						}
						if ( !flg || ( !f2 && n < m ) || (v != 1 && n < v ))
							printf( "%lld does not divide %lld!\n", m, n );
						else
							printf( "%lld divides %lld!\n", m, n );
			}
			return 0;
}

