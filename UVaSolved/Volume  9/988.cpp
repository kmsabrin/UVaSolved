#include <stdio.h>
#include <string.h>

int a[100001];

int d[100001];

void main()
{
	int i, j, k, n, s;

	//freopen ( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) != EOF )
	{		
		for ( i = 0; i < n; ++i )
		{			
			a[i] = d[i] = 0;
		}
		
		a[0] = 1;

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &j );
			
			if ( j == 0 )
			{
				d[i] = 1;
				
				
			}

			while ( j-- )
			{
				scanf( "%d", &k );

				a[k] += a[i];
			}
		}

		for ( i = j = 0; i < n; ++i )
		{		
			if ( d[i] )
			{				
				j += a[i];
			}	
		}
				
		printf( "%d\n", j );
	}
}

