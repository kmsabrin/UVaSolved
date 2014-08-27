#include <stdio.h>

int count_zero( int n )
{
	int i, j, k, t;
	long long m;

	if ( n < 0 )
	{
		return 0;
	}

	k = n / 10;
	m = 100;
	t = 10;
	i = n / m;

	while ( i )
	{
		j = n % m;

		if ( j >= t )
		{
			k += i * t;
		}
		else
		{
			k += ( i - 1 ) * t + ( j + 1 );
		}

		m *= 10;
		t *= 10;
		i = n / m;
	}

	return k + 1;
}

int main()
{
	int m, n;

	while ( scanf( "%d %d", &m, &n ) )
	{
		if ( m == -1 )
		{
			break;
		}

		printf( "%d\n", count_zero( n ) - count_zero( m - 1 ) );
	}

	return 0;
}