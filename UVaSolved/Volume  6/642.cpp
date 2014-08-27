#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp( const void *i, const void *j )
{
	return strcmp( ( char * )i, ( char * )j );
}

int freq[110][130];
char dict[110][10];

int main()
{
	int i, j;
	char str[10];
	int tmp[130];
	int word = 0, flg;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		gets( str );

		if ( strcmp( str, "XXXXXX" ) == 0 )
		{
			break;
		}

		strcpy( dict[word++], str );
	}

	qsort( dict, word, sizeof( dict[0] ), comp );
	
	memset( freq, 0, sizeof( freq ) );

	for ( i = 0; i < word; ++i )
	{
		for ( j = 0; j < ( int )strlen( dict[i] ); ++j )
		{
			++freq[i][dict[i][j]];
		}
	}

	while ( 1 )
	{
		gets( str );

		if ( strcmp( str, "XXXXXX" ) == 0 )
		{
			break;
		}

		memset( tmp, 0, sizeof( tmp ) );

		for ( i = 0; i < ( int )strlen( str ); ++i )
		{
			++tmp[str[i]];
		}

		for ( i = flg = 0; i < word; ++i )
		{
			for ( j = 0; j < 130; ++j )
			{
				if ( tmp[j] != freq[i][j] )
				{
					break;
				}
			}

			if ( j == 130 )
			{
				puts( dict[i] );
				flg = 1;
			}
		}

		if ( flg == 0 )
		{
			puts( "NOT A VALID WORD" );
		}

		puts( "******" );

	}

	return 0;
}
