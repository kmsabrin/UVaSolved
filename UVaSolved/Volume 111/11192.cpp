#include <stdio.h>
#include <string.h>

int main()
{
	int nG, gL, i, j, k;

	char str[111];

	while ( scanf( "%d", &nG ) && nG )
	{
		scanf( "%s", str );

		gL = strlen( str ) / nG;

		k = gL - 1;

		while ( nG )
		{
			for ( i = 0, j = k; i < gL; ++i, --j )
			{
				printf( "%c", str[j] );
			}

			k += gL;

			--nG;
		}

		printf( "\n" );
	}

	return 0;
}

