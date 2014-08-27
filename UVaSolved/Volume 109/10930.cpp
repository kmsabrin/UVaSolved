#include <stdio.h>
#include <string.h>

char t[30001];
int num[101];

int main()
{
	int i, j, n, k, p;
	int max, alive, c = 0;

	while ( scanf( "%d", &n ) != EOF )
	{

		memset( t, 0, sizeof( t ) );
		alive = 1;

		p = 0;

		scanf( "%d", &k );
		num[p++] = k;

		t[k] = 1;
		max = k;

		for ( i = 1; i < n; ++i )
		{
			scanf( "%d", &k );

			if ( k <= num[p - 1] )
				alive = 0;

			num[p++] = k;

			if ( t[k] )
				alive = 0;

			if ( alive )
			{
				for ( j = max; j >= 0; --j )				
					if ( t[j] )
						t[j + k] = 1;
				
				max = max + k;

				t[k] = 1;
			}
		}

		printf( "Case #%d:", ++c );

		for ( i = 0; i < p; ++i )
			printf( " %d", num[i] );
		printf( "\n" );

		if ( alive )
			printf( "This is an A-sequence." );
		else
			printf( "This is not an A-sequence." );

		printf( "\n" );

	}

	return 0;

}