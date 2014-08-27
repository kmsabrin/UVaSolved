#include <stdio.h>

int p[100001], q[100001];

void main()
{
	int T, c = 0;
	int N;
	int flg, start, target, has, needs;
	int i;
	int h, n;	

	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d", &N );

		h = n = 0;

		for ( i = 1; i <= N; ++i )
		{
			scanf( "%d", &p[i] );
			h += p[i];
		}

		for ( i = 1; i <= N; ++i )
		{
			scanf( "%d", &q[i] );
			n += q[i];
		}

		if ( h < n )
		{
			printf( "Case %d: Not possible\n", ++c );
			continue;
		}

		start = 1;
		target = N;
		
		has = needs = flg = 0;

		for ( i = 1; i <= N; ++i )
		{
			has += p[i];
			needs += q[i];
			
			if ( has < needs )
			{
				if ( i < start )
				{
					break;
				}

				start = i + 1;
				target = i;

				has = needs = 0;
			}	
			else if ( !( target ^ i ) )
			{
				flg = 1;
				break;
			}

			
			if ( !( i ^ N ) )
			{
				i = 0;
			}
		}

		if ( !flg )
		{
			printf( "Case %d: Not possible\n", ++c );
		}
		else
		{
			printf( "Case %d: Possible from station %d\n", ++c, start );
		}
	}
}