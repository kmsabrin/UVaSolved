#include <stdio.h>

int divide( char a[], char b[], long long v ) 
{
	long long i, s, d;

	for ( i = s = 0, d = 0; a[i]; ++i )
	{
		s = s * 10 + a[i] - 48;

		if ( d )
		{
			if ( s < v )
			{
				if ( b[0] == '/' )
				{
					printf( "0" );
				}
			}
			else
			{
				if ( b[0] == '/' )
				{
					printf( "%lld", s / v );
				}

				s %= v;
			}
		}
		else
		{
			if ( s >= v )
			{
				if ( b[0] == '/' )
				{
					printf( "%lld", s / v );
				}

				s %= v;
				
				d = 1;
			}
		}
	}

	if ( !d && b[0] == '/' )
	{
		printf( "0" );
	}

	if ( b[0] == '%' )
	{
		printf( "%lld", s );
	}

	printf( "\n" );

	return 0;
}

int main()
{	
	long long v;

	char a[1000], s[5];

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%s %s %lld", a, s, &v ) != EOF )
	{		
		divide( a, s, v );
	}

	return 0;
}

