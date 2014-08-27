#include <stdio.h>

int main()
{
	int a, b, i, j, k;
	int cnt, max;

	while ( 1 )
	{

		scanf( "%d %d", &a, &b );

		if ( a == 0 && b == 0 )
		{
			break;
		}

		max = k = cnt = 0;

		for ( i = 1;  ; ++i )
		{
			
			j = ( a - b * i );

			if ( j <= 0 )
			{
				break;
			}

			j = j * i;

			if ( j > max )
			{
				max = j;
				cnt = 1;
				k = i;
			}
			else if ( j == max )
			{
				++cnt;
			}
		}

		if ( cnt > 1 )
		{
			k = 0;
		}

		printf( "%d\n", k ) ;
	}

	return 0;
}


