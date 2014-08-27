#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, t, tc, left, right, m, l, s1, s2;
	char str[10];

	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d %d", &l, &m );

		l = l * 100;

		s1 = s2 = l;

		for ( i = left = right = 0; i < m; ++i )
		{
			scanf( "%d %s", &j, str );

			if ( !strcmp( str, "left" ) )
			{
				if ( s1 >= j )
				{
					if ( s1 == l )
						++left;
					s1 = s1 - j;
				}
				else
				{
					s1 = l - j;
					++left;
				}
			}
			else
			{
				if ( s2 >= j )
				{
					if ( s2 == l )
						++right;
					s2 = s2 - j;
				}
				else
				{
					s2 = l - j;
					++right;
				}
			}
		}

		if ( left > right )
		{
			t =  2 * left - 1;
		}
		else
		{
			t =  2 * right;
		}

		printf( "%d\n", t );

	}

	return 0;
}