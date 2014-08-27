#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[26][26];

char used[26];

int exc[26], fns[26];

void call( int s )
{
	int i, m;

	for ( i = m = 0; i < 26; ++i )
	{
		if ( a[s][i] )
		{
			if ( fns[i] == -1 )
			{
				call( i );
			}

			if ( fns[i] > m )
			{
				m = fns[i];
			}
		}
	}

	fns[s] = m + exc[s];
}

void main()
{
	int i, j, p, m, T;

	char str[35], *ptr;	

	//freopen( "a.in", "r", stdin );

	T = atoi( gets( str ) );

	getchar();

	while ( T-- )
	{
		for ( i = 0; i < 26; ++i )
		{
			for ( j = i; j < 26; ++j )
			{
				a[i][j] = a[j][i] = 0;
			}

			used[i] = 0;

			fns[i] = -1;
		}

		while ( gets( str ) && *str )
		{			
			ptr = strtok( str, " " );			

			p = *ptr - 65;	
			
			if ( used[p] )
			{
				continue;
			}

			used[p] = 1;


			exc[p] = atoi( ptr = strtok( NULL, " " ) );


			if ( ptr = strtok( NULL, " " ) )
			{						
				while( *ptr )
				{
					a[p][*ptr - 65] = 1;
					++ptr;
				}
			}
		}

		for ( i = 0; i < 26; ++i )
		{
			if ( used[i] && fns[i] == -1 )
			{
				call( i );
			}
		}

		for ( i = m = 0; i < 26; ++i )
		{			
			if ( used[i] && fns[i] > m )
			{
				m = fns[i];
			}
		}

		printf( "%d\n", m );

		if ( T )
		{
			printf( "\n" );
		}
	}
}
