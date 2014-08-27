#include <stdio.h>
#include <string.h>

long long a[51][51][51];


long long bc( long long n, long long k, long long m )
{	
	if ( n < 1 || k < 1 || m < 1 )
	{
		return 0;
	}

	if ( a[n][k][m] == -1 )
	{
		a[n][k][m] = 0;

		for ( long long i = 1; i <= m; ++i )
		{
			a[n][k][m] += bc( n - i, k - 1, m );
		}
	}

	return a[n][k][m];
}

void main()
{	
	long long n, k, m;

	memset( a, -1, sizeof( a ) );

	for ( n = 1; n <= 50; ++n )
	{
		for ( m = n; m <= 50; ++m )
		{
			a[n][1][m] = 1;
		}	
	}
	
	while ( scanf( "%lld %lld %lld", &n, &k, &m ) != EOF )
	{
		printf( "%lld\n", bc( n, k, m ) );
	}
}
