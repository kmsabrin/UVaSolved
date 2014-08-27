#include <math.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char str[201];
	int a[100];
	int s, l;
	int i, j;

	for ( i = 0, s = 0; i < 100; ++i )
	{
		j = i % 4;

		if ( !j )
		{
			j = 4;
		}

		s = ( s + (int)pow( i, j ) ) % 10; 

		a[i] = s;
	}

	while ( 1 )
	{
		gets( str );

		if ( str[0] == '0' )
		{
			break;
		}

		l = strlen( str );
		
		if ( l > 1 )
		{
			s = ( str[l - 2] - 48 ) * 10 + str[l - 1] - 48;
		}
		else
		{
			s = str[l - 1] - 48;
		}

		printf( "%d\n", a[s] );
	}
}
