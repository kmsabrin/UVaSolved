#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 60000

int main()
{
	int c[101];

	char coin[MAX];

	int i, j, k, t, n;

	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d", &n );

		for ( i = j = 0; i < n; ++i )
		{
			scanf ( "%d", &c[i] );
			j += c[i];
		}

		memset( coin, 0, MAX * sizeof(char) );

		coin[0] = 1;

		for ( i = 0; i < n; ++i )
		{
			for ( k = j; k >= 0; k-- ) // we go backwards to avoid repetition
			{
				if ( coin[k] )
				{
					coin[k + c[i]] = 1;
				}
			}
		}

		for ( i = j / 2;  ; --i )
		{
		       if ( coin[i] )
	      	 {
				printf( "%d\n", abs ( ( j - i ) - i ) );
				break;
		       }
		}
	}

	return 0;
}
