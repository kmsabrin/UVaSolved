#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char str[17];

	gets( str );
	while ( gets( str )  )
	{
		if ( str[0] == '_' )
			break;

		j = 0;
		for ( i = 2; i < 10; ++i )
		{
			if ( str[i] == 'o' )
				j = j * 2 + 1;
			else if ( str[i] == ' ' )
				j = j * 2;
			else
				;
		}
		printf( "%c", j );
	}
	return 0;
}
