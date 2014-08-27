#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char m[110], n[110];
	int i, j, p, q;

	while (1 )
	{
		scanf( "%s %s", m, n );

		if ( m[0] == '0' && n[0] == '0' )
		{
			break;
		}

		if ( n[0] == '0' )
		{
			printf( "1\n" );
		}

		p = strlen( m );

		if ( p < 2 )
		{
			i = atoi( m );
		}
		else
		{
			i = ( m[p - 2] - 48 ) * 10 + m[p - 1] - 48;
		}

		q = strlen( n );

		if ( q < 2 )
		{
			j = atoi( n ) % 4;
		}
		else
		{
			j = ( ( n[q - 2] - 48 ) * 10 + ( n[q - 1]  - 48 ) ) % 4;
		}

		if ( !j )
		{
			j = 4;
		}

		printf( "%d\n", (int)pow( (double)i, j ) % 10 );
	}
}