#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000000000

void main()
{
	unsigned int pos[35], neg[55];
	int i, j;
	int flg[35];
	int m, n, p;
	int T, c = 0;

	pos[0] = 1;

	for ( i = 1, j = 4; pos[i - 1] <= MAX; ++i )
	{
		pos[i] = pos[i - 1] + j;

		j = j * 4;		
	}

	neg[0] = 2;

	for ( i = 1, j = 8; neg[i - 1] <= MAX; ++i )
	{
		neg[i] = neg[i - 1] + j;

		j = j * 4;
	}

	scanf( "%d", &T ) ;

	while ( T-- )
	{
		scanf( "%d", &n );

		printf( "Case #%d: ", ++c );

		if ( n == 0 )
		{
			printf( "0\n" );
			continue;
		}

		memset( flg, 0, sizeof( flg ) );

		while ( 1 )
		{
			if ( n == 0 )
			{
				break;
			}
			else if ( n > 0 )
			{
				for ( i = 0; ; ++i )
				{
					if ( n <= pos[i] )
					{
						break;
					}
				}

				p = i * 2;

				flg[p] = 1;

				n = n - (int)pow( 2, p );
			}
			else 
			{
				m = -n;

				for ( i = 0; ; ++i )
				{
					if ( m <= neg[i] )
					{
						break;
					}
				}

				p = ( i * 2 ) + 1;

				flg[p] = 1;

				n = n + (int)pow( 2, p );
			}			
		}

		i = 34;

		while ( flg[i] == 0 )
		{
			--i;
		}

		while ( i > -1 )
		{
			printf( "%d", flg[i] );

			--i;
		}

		printf( "\n" );
	}
}



