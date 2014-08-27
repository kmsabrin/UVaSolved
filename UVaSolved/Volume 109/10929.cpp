#include <stdio.h>

int main()
{
	char str[1010];
	int i, s;

	while ( 1 )
	{
		gets( str );

		if ( str[0] == '0' && str[1] == '\0' )
			break;

		for ( i = s = 0; str[i]; ++i )
		{
			s = s * 10 + str[i] - 48;
			s = s % 11;
		}

		if ( !s )
			printf( "%s is a multiple of 11.\n", str );
		else
			printf( "%s is not a multiple of 11.\n", str );
	}

	return 0;
}


		/*
		THIS ALSO WORKS

		i = s = t = 0;

		while( 1 )
		{
			if ( str[i] )
			{
				s += str[i] - 48;
				++i;
			}
			else
				break;


			if ( str[i] )
			{
				t += str[i] - 48;
				++i;
			}
			else
				break;
		}

		THEN CHECK ( S - T ) % 11
		*/

