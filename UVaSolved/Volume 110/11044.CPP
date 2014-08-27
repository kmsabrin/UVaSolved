#include <stdio.h>

int main()
{
	long long tc;
	long long i, j, m, n;

	scanf( "%lld", &tc );

	while ( tc-- )
	{
		scanf( "%lld %lld", &n, &m );

		i = n - 2;
		j = m - 2;

		if ( i % 3 == 0 )
		{
			i = i / 3;
		}
		else
		{
			i = ( i / 3 ) + 1;
		}

		if ( j % 3 == 0 )
		{
			j = j / 3;
		}
		else
		{
			j = ( j / 3 ) + 1;
		}

		printf( "%lld\n", i * j );
	}

	return 0;
}
