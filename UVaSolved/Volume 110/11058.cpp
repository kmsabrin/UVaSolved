#include <stdio.h>
#include <string.h>

int main()
{
	char str[150], tmp[10], tmp2[10], a[150];
	char res[150][150], t = 0;
	char c, d;
	int i, j, k, r;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%s", str ) != EOF )
	{
		for ( i = 0; i < 26; ++i )
		{
			scanf( "%s", tmp );
			c = tmp[0];
			a[i + 97] = c;
		}

		scanf( "%d", &r );

		memset( res, -1, sizeof( res ) );

		for ( i = 0; i < r; ++i )
		{
			scanf( "%d %s %s", &j, tmp, tmp2 );
			c = tmp[0];
			d = tmp2[0];

			for ( k = j; k < 150; ++k )
			{
				res[c][k] = d;
			}
		}

		printf( "Case #%d: The encoding string is ", ++t ); 

		for ( i = 0; str[i]; ++i )
		{
			c = str[i];

			//printf( "%c\n", c );

			if ( res[c][i] != -1 )
			{
				printf( "%c", res[c][i] );
			}
			else
			{
				printf( "%c", a[c] );
			}
		}

		printf( ".\n\n" );
	}

	return 0;
}
