#include <stdio.h>

int main()
{
	int d[51], n, i;

	while ( scanf( "%d", &n ) && n > -1 )
	{
		if ( n == 0 )
		{
			printf( "0\n" );

			continue;
		}

		for ( i = 0; n; ++i )
		{
			d[i] = n % 3;

			n /= 3;
		}

		for ( --i; i > -1; --i )
		{
			printf( "%d", d[i] );
		}

		printf( "\n" );
	}

	return 0;
}