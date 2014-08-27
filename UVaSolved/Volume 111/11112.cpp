#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a, b, c, i, x, k, s;

	while ( 1 )
	{

		scanf( "%d %d %d", &a, &b, &c );

		if ( a == 0 && b == 0 && c == 0 )
		{
			break;
		}

		k = abs( a - c );

		if ( k % b )
		{
			printf( "No accounting tablet\n" );

			continue;
		}

		x = k / b;

		s = 0;


		i = x / 3;

		x = x - i * 3;

		s += i;


		i = x / 2;

		x = x - i * 2;

		s += i;

		
		s += x;

		printf( "%d\n", s );
	}
}