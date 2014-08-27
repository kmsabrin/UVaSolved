#include <stdio.h>
#include <string.h>

int main()
{
	long long a[20], b[20];
	long long n, m, i, j, max, c = 0;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%lld", &n ) != EOF )
	{
		max = 0;

		for ( i = 1; i <= n; ++i )
		{
			scanf( "%lld", &a[i] );

			if ( a[i] > max )
			{
				max = a[i];
			}
		}

		memcpy( b, a, sizeof( a ) );

		m = n - 1;

		for ( i = 2; i <= n; ++i, --m )
		{
			for ( j = 1; j <= m; ++j )
			{
				b[j] = b[j] * a[j + i - 1];				

				if ( b[j] > max )
				{
					max = b[j];
				}
			}			
		}

		printf( "Case #%lld: The maximum product is %lld.\n\n", ++c, max );
	}

	return 0;
}