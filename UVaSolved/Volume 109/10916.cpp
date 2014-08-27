#include <stdio.h>
#include <math.h>

int main()
{
	int a[2161];

	double k, m;

	int i, l, j;

	a[1960] = 3;

	j = 4;

	k = log( 1.0 ) + log( 2.0 ) + log( 3.0 );

	l = 3;
	
	for ( i = 1970; i <= 2160; i += 10 )
	{
		j *= 2;

		m = (double)j * log( 2.0 );

		while ( 1 )
		{
			if ( k > m )
			{
				break;
			}

			++l;

			k += log( (double)l );
		}

		a[i] = l - 1;
	}

	while ( scanf( "%d", &i ) && i )
	{
		i -= i % 10;

		printf( "%d\n", a[i] );
	}

	return 0;
}




