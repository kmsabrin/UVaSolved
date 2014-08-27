#include <stdio.h>
#include <string.h>

void main()
{
	int v[1001];
	int f[1001];	
	int nf[1001];
	int i, j, min, n, last;
	
	char str[1001][20], tmp[20], keep[20];

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &n ) && n )
	{		
		last = 0;

		for ( i = n; i >= 1; --i )
		{
			scanf( "%s %s %s", str[i], tmp, keep );
			
			f[i] = 0;
			
			if ( keep[0] == '+' )
			{
				f[i] = 1;
			}

			if ( f[i] && !last )
			{
				last = i;
			}
		}

		if ( !last )
		{
			printf( "0\n" );

			continue;
		}
				
		v[1] = 0;
				
		for ( i = 2; i <= n; ++i )
		{
			if ( strcmp( str[i], str[i - 1] ) >= 0 )
			{
				v[i] = v[i - 1] + 1;				
			}
			else
			{
				v[i] = v[i - 1];				
			}			
		}

		i = 1;

		while ( i <= n && !f[i] && strcmp( str[i], str[i + 1] ) > 0 )
		{
			++i;
		}

		nf[i] = 1;
		
		for ( ++i; i <= n; ++i )
		{
			j = i - 1;

			min = 0xFFFFFF;			
				
			while ( j > 0 && v[i] - v[j] <= 1 ) 
			{				
				if ( v[i] - v[j] == 1 && strcmp( str[i], str[j] ) < 0 )
				{
					break;
				}

				if ( nf[j] < min )
				{
					min = nf[j];					
				}

				if ( f[j] )
				{
					break;
				}

				--j;				
			}

			nf[i] = min + 1;		
		}
				
		printf( "%d\n", nf[last] );
	}
}