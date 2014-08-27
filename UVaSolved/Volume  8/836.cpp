#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[30];
	int cum[30][30];
	int i, j, k;
	int sum, max, size, add;
	int r, c;
	int t;

	/*freopen( "a.in", "r", stdin );*/

	t = atoi ( gets( str ) );
	getchar();
	
	while ( t-- )
	{
		
		for ( i = 0; i < c; ++i )		
			cum[0][i] = 0;

		r = 1;	
		while ( gets( str ) && str[0] )
		{
			for ( j = 0; str[j]; ++j )
			{
				if ( str[j] == 48 )
					cum[r][j] = 1;	// 1 if 0 
				else
					cum[r][j] = 0;	// 0 if 1
			}
			++r;			
		}
		c = r = r - 1;
			
		for ( i = 1; i <= r; ++i )		
			for ( j = 0; j < c; ++j )						
				cum[i][j] = cum[i][j] + cum[i - 1][j];
			
		
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

					if ( sum == 0 )		// then all within the rectangle must be 0
						size += add;
					else				// not a rectangle full of 0
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

		if ( t )
			printf ( "\n" );
	}

	return 0;
}
