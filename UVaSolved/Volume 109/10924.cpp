#include <stdio.h>
#include <string.h>

#define M 100000

char p[M + 1];

int main()
{
	char s[1000];
	int sum;
	int i, j;
	
	memset( p, 0, sizeof( p ) );

	p[0] = 1; 
	p[1] = 0;

	for ( i = 2; i * i <= M; ++i )
		if ( !p[i] )
			for ( j = i * i; j <= M; j += i )
				p[j] = 1;

		
	while ( gets( s ) )
	{		
		sum = 0;
		for ( i = 0; s[i]; ++i )
		{
			if ( s[i] >= 65 && s[i] <= 90 )
				sum += s[i] - 38;

			if ( s[i] >= 97 && s[i] <= 122 )
				sum += s[i] - 96;
		}
	

		if ( p[sum] )
			printf( "It is not a prime word.\n" );
		else
			printf( "It is a prime word.\n" );
	}

	return 0;
}