#include <stdio.h>
#include <string.h>

char str[20][20], tmp[20];

void main()
{
	int i, j, k, f, p, q, c = 0;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%s", str[0] ) != EOF )
	{
		i = 1;

		while ( 1 )
		{
			scanf( "%s", tmp );

			if ( tmp[0] == '9' )
			{
				break;
			}

			strcpy( str[i++], tmp );
		}

		k = i;

		f = 1;

		for ( i = 0; i < k; ++i )
		{
			for ( j = 0; j < k; ++j )
			{
				if ( i == j )
				{
					continue;
				}

				for ( p = q = 0; str[i][p] && str[j][p]; ++p )
				{
					if ( str[i][p] != str[j][p] )
					{
						++q;
					}
				}

				if ( !q )
				{
					f = 0;
					break;
				}
			}

			if ( !q )
			{
				break;
			}
		}

		if ( f )
		{
			printf( "Set %d is immediately decodable\n", ++c );
		}
		else
		{
			printf( "Set %d is not immediately decodable\n", ++c );
		}
	}
}
