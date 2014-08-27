#include <stdio.h>
#include <string.h>

int main()
{
	char a[10000];
	int i, j, k, m, r, c, flg, count;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%d", &k );

		if ( !k ) 
			break;
	
		scanf( "%d", &m );

		memset( a, 0, sizeof( a ) );

		for ( i = 0; i < k; ++i )
		{
			scanf( "%d", &j );
			a[j] = 1;
		}

		flg = 1;

		for ( i = 0; i < m; ++i )
		{
			scanf( "%d", &c );

			scanf( "%d", &r );

			count = 0;
			
			for ( j = 0; j < c; ++j )
			{
				scanf( "%d", &k );
				if ( a[k] )
					++count;
			}

			if ( count < r )
				flg = 0;
		}

		if ( flg )
			printf( "yes\n" );
		else
			printf( "no\n" );
	}

	return 0;

}
