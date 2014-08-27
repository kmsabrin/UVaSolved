#include <stdio.h>
#include <string.h>

char a[100][100], b[100][100];
char flg[1000];

int main()
{
	char s[10], d[10];
	int u, v, n, cnt;
	int i, j, k, f; 
	int tc;
	int d1, d2;

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &tc );

	while ( tc-- )
	{

		memset( flg, 0, sizeof( flg ) );

		scanf( "%d", &n );

		cnt = 1;

		memset( a, 0, sizeof( a ) );

		for ( i = 0; i < n; ++i )
		{			
			scanf( "%s %s", s, d );

			if ( flg[s[0]] == 0 )
			{
				flg[s[0]] = cnt++;
			}
			
			u = flg[s[0]];

			if ( flg[d[0]] == 0 )
			{
				flg[d[0]] = cnt++;
			}
			
			v = flg[d[0]];

			a[u][v] = a[v][u] = 1;
		}

		d1 = cnt;



		memset( flg, 0, sizeof( flg ) );

		scanf( "%d", &n );

		cnt = 1;

		memset( b, 0, sizeof( b ) );

		for ( i = 0; i < n; ++i )
		{			
			scanf( "%s %s", s, d );

			if ( flg[s[0]] == 0 )
			{
				flg[s[0]] = cnt++;
			}
			
			u = flg[s[0]];

			if ( flg[d[0]] == 0 )
			{
				flg[d[0]] = cnt++;
			}
			
			v = flg[d[0]];

			b[u][v] = b[v][u] = 1;
		}

		d2 = cnt;

		if ( d1 != d2 )
		{
			printf( "NO\n" );
		}
		else
		{
			for ( k = 1; k < d1; ++k )
			{
				for ( i = 1; i < d1; ++i )
				{
					for ( j = 1; j < d1; ++j )
					{
						a[i][j] = a[i][j] || ( a[i][k] && a[k][j] );
					}
				}
			}

			for ( k = 1; k < d1; ++k )
			{
				for ( i = 1; i < d1; ++i )
				{
					for ( j = 1; j < d1; ++j )
					{
						b[i][j] = b[i][j] || ( b[i][k] && b[k][j] );
					}
				}
			}


			f = 1;
			
			for ( i = 0; i < d1; ++i )
			{
				for ( j = 0; j < d1; ++j )
				{
					if ( a[i][j] != b[i][j] )
					{
						f = 0;
					}
				}
			}

			if ( f )
			{
				printf( "YES\n" );
			}
			else
			{
				printf( "NO\n" );
			}

			scanf( "\n" );

			if ( tc )
			{
				scanf( "\n" );
				printf( "\n" );
			}

		}

	}

	return 0;
}




