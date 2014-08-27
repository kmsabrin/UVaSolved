#include <stdio.h>
#include <string.h>

long long a[20][20];

long long n;

long long call( long long i, long long j )
{		
	if ( a[i][j] == -1 )
	{		
		long long s, m, k, t;

		if ( i >= j )
		{
			s = 0;

			if ( i < n )
			{
				m = 0;

				for ( k = i + 1; k <= n; ++k )
				{				
					t = call( k, 1 ) + call( k, j );				

					if ( t > m )
					{
						m = t;
					}					
				}

				s += m;
			}

			if ( j > 1 )
			{
				m = 0;

				for ( k = 1; k < j; ++k )
				{			
					t = call( i, k ) + call( n, k );				

					if ( t > m )
					{
						m = t;
					}					
				}

				s += m;
			}

			a[i][j] = s;
		}
		else
		{
			m = 0;

			for ( k = i; k < j; ++k )
			{			
				t = call( i, k ) + call( k + 1, j );							

				if ( t > m )
				{
					m = t;
				}
			}

			a[i][j] = m;
		}		
	}

	return a[i][j];
}

void main()
{
	long long k;
	
	while ( scanf( "%lld %lld", &n, &k ) != EOF )
	{
		memset( a, -1, sizeof( a ) );

		a[n][1] = k;

		printf( "%lld\n", call( 1, n ) );
	}
}
