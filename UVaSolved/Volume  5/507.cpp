#include <stdio.h>

int main()
{
	int nice[20010];
	int i;
	int tc, s, st, start, end, sum, max, t = 1;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{

		scanf( "%d", &s );

		for ( i = 1; i < s; ++i )
		{
			scanf( "%d", &nice[i] );
		}

		sum = st = max = 0;
		
		for ( i = 1; i < s; ++i )
		{
			sum += nice[i];

			//printf( "sum = %d\n", sum );

			if ( sum < 0 )
			{
				sum = 0;
				st = i;
			}

			if ( sum > max )
			{
				max = sum;
				start = st;
				end = i;
			}

			if ( sum == max )
			{
				if ( ( i - st ) > ( end - start ) )
				{
					start = st;
					end = i;
				}
			}
									
		}

		if ( max == 0 )
		{
			printf( "Route %d has no nice parts\n", t++ );
		}
		else
		{
			printf( "The nicest part of route %d is between stops %d and %d\n", t++, start + 1, end + 1 );
		}


	}

	return 0;
}




