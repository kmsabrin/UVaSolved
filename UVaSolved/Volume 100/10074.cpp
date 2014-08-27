#include <stdio.h>

int main()
{
	int cum[10101][107];
	int i, j, k;
	int sum, max, size, add;
	int r, c;
	
	while ( scanf( "%d %d", &r, &c ) && r && c )
	{
		for ( i = 0; i < c; ++i )
			cum[0][i] = 0;

		for ( i = 1; i <= r; ++i )
		{
			for ( j = 0; j < c; ++j )
			{
				scanf( "%d", &k );
				cum[i][j] = cum[i - 1][j] + k;
			}
		}

		max = 0;
		for ( i = r; i > 0; --i )
		{
			for ( j = i - 1; j > -1; --j )
			{
				sum = 0;
				add = i - j;
				size = 0;
				for ( k = 0; k < c; ++k )
				{
					sum += cum[i][k] - cum[j][k];

					if ( sum == 0 ) 
						size += add;
					else
					{
						if ( size > max )
							max = size;
						sum = size = 0;
					}
				}

				if ( sum == 0 )
					if ( size > max )
						max = size;
			}
		}
		
		printf ( "%d\n", max );
	}

	return 0;
}
