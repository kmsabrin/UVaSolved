#include <stdio.h>
#include <string.h>

int main()
{
	char a[30][30];
	char value[150];
	char done[30];
	char tmp[30];
	char s[5];

	int n;
	int m;
	int i;
	int j;
	int k;
	int p;
	int q;
	int v;
	int r;
	int f;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) != EOF )
	{
		scanf( "%d", &m );

		scanf( "%s", s );

		memset( value, 0, sizeof( value ) );
		memset( a, 0, sizeof( a ) );

		v = 0;

		value[s[0]] = ++v;
		value[s[1]] = ++v;
		value[s[2]] = ++v;

		for ( i = 0; i < m; ++i )
		{
			scanf( "%s", s );

			if ( value[s[0]] )
			{
				p = value[s[0]];
			}
			else
			{
				p = value[s[0]] = ++v;
			}

			if ( value[s[1]] )
			{
				q = value[s[1]];
			}
			else
			{
				q = value[s[1]] = ++v;
			}

			a[p][q] = a[q][p] = 1;

		}

		/*
		for ( i = 1; i <= n; ++i )
		{
			for ( j = 1; j < n; ++j )
			{
				printf( "%2d", a[i][j] );
			}
			printf( "\n" );
		}
		*/

		if ( n == 3 )
		{
			printf( "WAKE UP IN, 0, YEARS\n" );
			continue;
		}

		memset( done, 0, sizeof( done ) );

		done[1] = done[2] = done[3] = -1;

		r = n - 3;

		memcpy( tmp, done, sizeof( tmp ) );

		for ( i = 1;	; ++i )
		{
			f = 1;

			for ( j = 4; j <= n; ++j )
			{
				if ( done[j] != -1 )
				{
					tmp[j] = 0;

					for ( k = 1; k <= n; ++k )
					{
						if ( done[k] == -1 && a[j][k] )
						{
							++tmp[j];
						}
					}

					if ( tmp[j] >= 3 )
					{
						tmp[j] = -1;
						f = 0;
						--r;
					}
				}
			}

			memcpy( done, tmp, sizeof( tmp ) );

			if ( r == 0 )
			{
				printf( "WAKE UP IN, %d, YEARS\n", i );
				break;
			}

			if ( f && r )
			{
				printf( "THIS BRAIN NEVER WAKES UP\n" );
				break;
			}
		}
	}

	return 0;
}