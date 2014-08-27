#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long tc, i, j, k, a, b;

	scanf( "%lld", &tc );

	while ( tc-- )
	{
		scanf( "%lld %lld", &a, &b );

		if ( a < 0 )
		{
			a *= -1;
		}

		if ( b < 0 )
		{
			b *= -1;
		}

		if ( a == 0 && b == 0 )
		{
			printf( "1\n" );
		}
		else if ( a == 0 && b )
		{
			printf( "2\n" );
		}
		else if ( a && b == 0 )
		{
			printf( "1\n" );
		}
		else if ( a == b && a <= 128 )
		{
			printf( "4\n");
		}
		else
		{
			printf( "TOO COMPLICATED\n" );
		}
	}

	return 0;
}


