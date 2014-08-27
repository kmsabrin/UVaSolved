#include <stdio.h>
#include <string.h>

int main()
{
	int d[1010];
	int min, i, count, t, p;
	char str[10000], *q;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d", &p );
		getchar();

		for ( i = 0; i < p; ++i )
		{

			gets( str );

			count = 0;

			q = strtok( str, " " );
			++count;

			while ( q = strtok( NULL, " " ) )
				++count;

			d[i] = count;
		}

		if ( t ) 
			gets( str );

		min = d[0];

		for ( i = 1; i < p; ++i )
			if ( d[i] < min ) 
				min = d[i];

		for ( i = 0; i < p; ++i )
			if ( d[i] == min )
			{
				printf( "%d", i + 1 );
				break;
			}
	
		for ( ++i; i < p; ++i )
			if ( d[i] == min )
				printf( " %d", i + 1 );

		printf( "\n" );
	}

	return 0;
}
