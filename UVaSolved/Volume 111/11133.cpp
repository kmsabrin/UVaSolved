#include <stdio.h>
#include <string.h>

int a[45][45];

void main()
{
	int i, j, k, n;
		
	n = 44;

	memset( a, 0, sizeof( a ) );

	for ( i = 0; i <= n; ++i )
	{
		a[i][i] = 1;
	}

	for ( i = 0; i <= n; ++i )
	{
		for ( j = i + 1; j <= n; ++j )
		{
			for ( k = j - 1; k >= i; --k )
			{
				if ( j % ( j - k ) == 0 )
				{
					a[i][j] += a[i][k];
				}
			}
		}
	}

	while ( 1 )
	{
		scanf( "%d %d", &j, &k );

		if ( !j && !k )
		{
			break;
		}

		printf( "%d %d %d\n", j, k, a[j][k] );
	}		
}