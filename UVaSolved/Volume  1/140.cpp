#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cnt, len, n;
char str[100], arr[100], used[100];

char a[30][30];
char r[30];
int min;

void check_band( char s[] )
{
	int m, d, M;

	M = 0;

	for ( int i = 0; s[i]; ++i )
	{
		m = 0;

		for ( int j = 0; s[j]; ++j )
		{
			if ( a[s[i] - 65][s[j] - 65] )
			{
				d = abs( j - i );

				if ( d > m )
				{
					m = d;
				}
			}
		}

		if ( m > M )
		{
			M = m;
		}
	}

	if ( M < min )
	{
		min = M;

		strcpy( r, s );
	}
}

void perm()
{
	if ( cnt == n )
	{
		str[cnt] = 0;
		check_band( str );
		//puts( str );
		return;
	}

	for ( int i = 0; i < n; ++i )
	{
		if ( !used[i] )
		{
			str[cnt++] = arr[i];
			used[i] = 1;
			perm();
			--cnt;
			used[i] = 0;

			int j;
			for ( j = i + 1; arr[j] == arr[i]; ++j )
			;
			i = j - 1;
		}
	}
}

void generate_permutation( char s[] ) // works for repititions also
{
	strcpy( arr, s );
	n = strlen( arr );
	cnt = 0;
	memset( used, 0, sizeof( used ) );
	perm(); // generate n! different permutation
}

void main()
{
	int i, j, s, e;

	char st[100], flg[30], tmp[30], *p;

	//freopen( "a.in", "r", stdin );

	while ( gets( st ) )
	{
		if ( st[0] == '#' )
		{
			break;
		}

		memset( a, 0, sizeof( a ) );

		memset( flg, 0, sizeof( flg ) );

		p = strtok( st, ";" );

		strcpy( tmp, p );

		s = tmp[0] - 65;

		flg[s] = 1;

		for ( i = 2; tmp[i]; ++i )
		{
			e = tmp[i] - 65;

			flg[e] = 1;

			a[s][e] = a[e][s] = 1;
		}

		while ( p = strtok( NULL, ";" ) )
		{
			strcpy( tmp, p );

			s = tmp[0] - 65;

			flg[s] = 1;
	
			for ( i = 2; tmp[i]; ++i )
			{
				e = tmp[i] - 65;

				flg[e] = 1;

				a[s][e] = a[e][s] = 1;
			}
		}

		for ( i = j = 0; i < 30; ++i )
		{
			if ( flg[i] )
			{
				tmp[j++] = i + 65;
			}
		}

		tmp[j] = 0;

		min = 0xfffffff;

		generate_permutation( tmp );

		for ( i = 0; r[i]; ++i )
		{
			printf( "%c ", r[i] );
		}
		
		printf( "-> %d\n", min );
	}
}

