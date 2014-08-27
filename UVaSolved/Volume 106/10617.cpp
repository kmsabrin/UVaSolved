#include <stdio.h>
#include <string.h>

unsigned long long a[64][64];

void main()
{
	int i, j, k, l, n, T;
	
	char s[64];
	
	//freopen( "a.in", "r", stdin );
	
	s[0] = '?';

	scanf( "%d", &T );
	
	while (  T-- )
	{		
		scanf( "%s", s + 1 );

		n = strlen( s ) - 1;		
						
		for ( i = 1; i <= n; ++i )
		{
			for ( j = i; j <= n; ++j )
			{
				a[i][j] = 0;
			}

			a[i][i] = 1;
		}
						
		for ( l = 2; l <= n; ++l )
		{
			for ( i = 1; i <= n - l + 1; ++i )
			{
				j = i + l - 1;
								
				a[i][j] = a[i][j - 1] + 1;
				
				for ( k = i; k <= j - 1; ++k )
				{
					if ( s[k] == s[j] )
					{
						a[i][j] += a[k + 1][j - 1] + 1;
					}
				}
			}
		}
						
		printf( "%llu\n", a[1][n] ) ;
	}
}
