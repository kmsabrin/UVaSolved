#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, n, f, c = 0;
	int a[110];
	char b[21000];

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) != EOF )
	{
		f = 1;

		printf( "Case #%d: ", ++c ); 

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &a[i] );

			if ( i > 0 )
			{
				if ( a[i] <= a[i - 1] )
				{					
					f = 0;					
				}
			}

			if ( i == 0 && a[i] < 1 )
			{
				f = 0;
			}
		}

		if ( !f )
		{
			printf( "It is not a B2-Sequence.\n\n" );
			continue;
		}

		memset( b, 0, sizeof( b ) );

		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j <= i; ++j )
			{
				k = a[i] + a[j];
										
				if ( b[k] )
				{
					f = 0;
					break;
				}
				else
				{
					b[k] = 1;
				}
			}

			if ( !f )
			{
				break;
			}
		}

		if ( f )
		{
			printf( "It is a B2-Sequence.\n\n" );
		}
		else
		{
			printf( "It is not a B2-Sequence.\n\n" );
		}
				
	}

	return 0;
}