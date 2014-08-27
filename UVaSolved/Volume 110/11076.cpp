#include <stdio.h>

void main()
{
	int n;
	int a[10];
	int i, j, k;
	unsigned long long m, s, t;

	while ( scanf( "%d", &n ) && n )
	{
		for ( i = 0; i <= 9; ++i )
		{		
			a[i] = 0;
		}

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &j );
			++a[j];
		}

		for ( m = 1, k = 2; k <= n; ++k )
		{
			m *= k;
		}		

		for ( i = 0; i <= 9; ++i )
		{
			if ( a[i] )
			{
				for ( s = 1, k = 2; k <= a[i]; ++k )
				{
					s *= k;
				}

				m /= s;
			}
		}
		
		for ( i = s = 0; i <= 9; ++i )
		{
			s += ( ( m * a[i] ) / n ) * i;						
		}
		
		for ( i = t = 0; i < n; ++i )
		{
			t = t * 10 + s;
		}

		printf( "%llu\n", t );
	}
}

