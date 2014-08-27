#include <stdio.h>

int main()
{
	long long i, j, n, c;
	char s[101];


	while ( scanf( "%lld", &n ) && n )
	{
		c = 0;
		j = 0;

		for ( i = 1; i <= n; i *= 2 )		
		{
			if ( i & n )
			{
				++c;
				s[j++] = 49;
			}
			else
				s[j++] = 48;
		}

		printf( "The parity of " );

		for ( i = j - 1; i > -1; --i )
			printf( "%c", s[i] );
	
		printf( " is %lld (mod 2).\n", c );
	}
	

	return 0;
}



