#include <stdio.h>
#include <string.h>

int main()
{
	char s1[1000], s2[1000], str[1000], map[1000];
	int tc, i;

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &tc );

	while ( tc-- )
	{

		gets( s1 );

		gets( s2 );

		puts( s2 );

		puts( s1 );

		memset( map, 0, sizeof( map ) );

		for ( i = 0; i < ( int )strlen( s1 ); ++i )
		{
			map[s1[i]] = s2[i];
		}

		while ( gets( str ) && str[0] != NULL )
		{

			for ( i = 0; i < ( int )strlen( str ); ++i )
			{
				if ( map[str[i]] )
				{
					printf( "%c", map[str[i]] );
				}
				else
				{
					printf( "%c", str[i] );
				}
			}

			printf( "\n" );
		}

		if ( tc )
		{
			printf( "\n" );
		}
	}

	return 0;
}