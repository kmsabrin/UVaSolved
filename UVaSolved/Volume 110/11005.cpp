#include <stdio.h>

int main()
{
	int i, j, m, n, q, tc, t = 1;
	int cost, min;
	int c[40], ct[40];

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{

		for ( i = 0; i < 36; ++i )
		{
			scanf( "%d", &c[i] );
		}


		scanf( "%d", &q );

		printf( "Case %d:\n", t++ );

		for ( i = 0; i < q; ++i )
		{

			scanf( "%d", &n );

			min = 0x7fffffff;
		
			for ( j = 2; j <= 36; ++j )
			{

				m = n;
				cost = 0;

				while ( m )
				{
					cost += c[m % j];
					m /= j;
				}

				ct[j] = cost;

				if ( cost < min )
				{
					min = cost;
				}
			}


			printf( "Cheapest base(s) for number %d:", n );

			for ( j = 2; j <= 36; ++j )
			{
				if ( ct[j] == min )
				{
					printf( " %d", j );
				}
			}

			printf( "\n" );
		}

		if ( tc )
		{
			printf( "\n" );
		}
	}

	return 0;
}

