#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int need[] = { -1,
					1, 1, 
					2, 2,
					3, 3, 3, 3,
					4, 4, 4, 4, 4, 4, 4, 4,
					5, 5, 5, 5 };

	int i, j, k, m, s;
	int side, val, num, total;
	char tmp[20], str[1010];

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%s", tmp );

		if ( strcmp( tmp, "0D0" ) == 0 )
		{
			break;
		}

		num = atoi( tmp );

		for ( i = 0; tmp[i] != 'D'; ++i )
			;

		side = atoi( tmp + i + 1 );

		val = need[side];

		memset( str, 0, sizeof( str ) );

		scanf( "%s", str );

		for ( i = total = 0; num && str[i];  )
		{
			s = 0;

			for ( j = i, k = 0; str[j] && k < val; ++k, ++j )
			{
				if ( str[j] == 'H' )
				{
					m = 0;
				}
				else
				{
					m = 1;
				}

				s = s * 2 + m;
			}

			if ( k < val )
			{
				break;
			}

			++s;

			if ( s <= side )
			{									
				total += s;								
				--num;
			}
			
			i += val;
		}

		if ( total == 0 || num )
		{
			total = -1;
		}

		printf( "%d\n", total );
	}
}




				   