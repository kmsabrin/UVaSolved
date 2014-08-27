#include <stdio.h>

int main()
{
	int a[7], i, j, t, c = 0, n;

	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d", &n );

		j = 0;
		for ( i = 2; j < 4; ++i )

			if ( n % i == 0 && i * i != n )
			{
				a[j++] = i;
				a[j++] = n / i;
			}

		printf( "Case #%d: %d = %d * %d = %d * %d\n", ++c, n, a[0], a[1], a[2], a[3] );
	}
	return 0;
}

