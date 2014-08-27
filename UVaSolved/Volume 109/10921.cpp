#include <stdio.h>
#include <ctype.h>

int main()
{
	int a[150];
	int i;
	char str[100], j;

	a[97] = a[98] = a[99] = 2;
	a[100] = a[101] = a[102] = 3;
	a[103] = a[104] = a[105] = 4;
	a[106] = a[107] = a[108] = 5;
	a[109] = a[110] = a[111] = 6;
	a[112] = a[113] = a[114] = a[115] = 7;
	a[116] = a[117] = a[118] = 8;
	a[119] = a[120] = a[121] = a[122] = 9;

	while ( gets( str) )
	{
		for ( i = 0; str[i]; ++i )
		{
			if ( str[i] == '-' || str[i] == '1' || str[i] == '0' )
				printf( "%c", str[i] );
			else
			{
				j = tolower( str[i] );
				printf( "%d", a[j] );
			}
		}
		printf( "\n" );
	}

	return 0;
}

