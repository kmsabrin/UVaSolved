#include <stdio.h>
#include <stdlib.h>

int factor[1000];

int comp( const void *i, const void *j )
{
	return *( int * )i - *( int * )j;
}

int factorize( int n )
{
	int index = 0;
	for ( int i = 2; i * i <= n; ++i )
		if ( n % i == 0 )
		{
			factor[index++] = i;
			if ( i != n / i )
				factor[index++] = n / i;
		}
	qsort( factor, index, sizeof( int ), comp );
	return index;
}

int gcd( int a, int b )
{
	if ( b == 0 )
		return a;
	return gcd( b, a % b );
}

int lcm( int m, int n )
{
	return ( m / gcd( m, n ) ) * n;
}

int main()
{
	int i, k, n, index, count;

	while( scanf( "%d", &n ) && n )
	{
		index = factorize( n );
		count = 0;
		for ( i = 0; i < index - 1; ++i )
			for ( k = i + 1; k < index; ++k )
				if ( lcm( factor[i], factor[k] ) == n )
					++count;
		if ( n == 1 )	count = -1;
		printf( "%d %d\n", n, count + ( index + 2 ) );
	}

	return 0;
}