#include <math.h>
#include <stdio.h>
#include <string.h>

int str[50000];
int tmp[10];
int a[250][250];

int main()
{
	int c, len, n, k, i, j, b;

	//freopen( "a.in", "r", stdin );

	len = 0;
	
	while ( ( c = getchar() ) != EOF )
	{
		str[len++] = c;
	}

	n = ( int ) ceil( len / 6.0 );

	memset( a, -1, sizeof( a ) );

	j = 0;

	while ( n-- )
	{
		b = 64;
		k = 1;

		for ( i = 0; j < len && i < 6; ++i, ++j )
		{
			if ( j < 2 )
			{
				tmp[k++] = str[j];
				continue;
			}

			if ( a[str[j - 2]][str[j - 1]] != str[j] )
			{
				a[str[j - 2]][str[j - 1]] = str[j];
				tmp[k++] = str[j];
			}
			else
			{
				b += ( int ) pow( 2.0, i );
			}
		}

		tmp[0] = b;

		for ( i = 0; i < k; ++i )
		{
			printf( "%c", tmp[i] );
		}

	}

	return 0;
}



