

/* @JUDGE_ID: 34556CP 10098 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.117 - CRC: 8D740E60 **/
/** Date: 2004-10-03 17:54:47 +0200 **/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char grid[20][20], used[20], str[20];
int  path[20], len, n;

int comp( const void *i, const void *j )
{
	return *(char *)i - *(char *)j;
}

int call( int from )
{
	int i, j, f;
	if ( len == n )
	{
		for ( i = 0; i < n; ++i )
			printf( "%c", str[path[i]] );
		printf( "\n" );
		return 0;
	}

	for ( i = 0; str[i]; ++i )
	{
		if ( !used[i] && !grid[from][i] )
		{
			j = len - 1; f = 1;
			while ( j > -1 )
			{
				if ( grid[path[j]][i] )
				{
					f = 0;	break;
				}
				j--;
			}
			if ( !f ) continue;

			used[i] = 1;
			path[len++] = i;
			call( i );
			used[i] = 0;
			len--;
		}
	}
	return 0;
}

int main()
{
	int i, j, t;

	scanf( "%d", &t ); getchar();
	while ( t-- )
	{
		gets( str );
		memset( grid, 0, 20 * 20 );
		memset( used, 0, 20 );
		n = strlen( str );
		qsort( str, n, sizeof(char), comp);

		for ( i = 0; i < n; ++i )
		{
			for ( j = i + 1; j < n; ++j )
				if ( str[i] == str[j] )
					grid[j][i] = 1;
			grid[i][i] = 1;
		}
/*
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
				printf("%d ", grid[i][j]);
			printf("\n");
		}
*/
		for ( i = 0; str[i]; ++i )
		{
			used[i] = 1;
			len = 0;
			path[len++] = i;
			call(i);
			used[i] = 0;
		}
		printf( "\n" );
	}
	return 0;
}


