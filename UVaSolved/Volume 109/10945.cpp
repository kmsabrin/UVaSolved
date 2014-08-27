#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i, j, f;

	char r[10000], s[10000];

	//freopen( "a.in", "r", stdin );

	while ( gets( r ) )
	{
		if ( !strcmp( r, "DONE" ) )
			break;

		j = 0;
		for ( i = 0; r[i]; ++i )
			if ( isalpha( r[i] ) )
				s[j++] = toupper( r[i] );

		s[j] = 0;

		f = 1;
		for ( i = 0; i < j / 2; ++i )
			if ( s[i] != s[j - i - 1] )
			{
				f = 0;
				break;
			}

		if ( f )
			printf( "You won't be eaten!\n" );
		else
			printf( "Uh oh..\n" );
		
	}

	return 0;
}
