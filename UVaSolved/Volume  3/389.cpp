#include <stdio.h>
#include <string.h>

void to_decimal( char s[], int b, long &n )
{
	long m, r, i;

	n = 0, m = 1;

	for ( i = strlen( s ) - 1; i > -1; --i )
	{
		if ( s[i] > 60 )
		{
			r = s[i] - 55;
		}
		else
		{
			r = s[i] - 48;
		}

		n += r * m;
		
		m *= b;
	}	
}

void to_base_b( long n, int b, char s[] )
{
	int i, r, t;
	
	i = 0;

	if ( n == 0 )
	{
		s[i++] = 48;
	}

	while ( n )
	{
		r = n % b;

		n /= b;

		if ( r < 10 )
		{
			s[i++] = r + 48;
		}
		else
		{
			s[i++] = r + 55;
		}
	}

	s[i] = 0;

	for ( --i, r = 0; r < i; ++r, --i )
	{
		t = s[r]; s[r] = s[i]; s[i] = t;
	}
}

int legal( char s[], int b )
{
	int i, j;

	for ( i = 0; s[i]; ++i )
	{
		if ( s[i] > 60 )
		{
			j = s[i] - 55;
		}
		else
		{
			j = s[i] - 48;
		}

		if ( j >= b )
		{
			return 0;
		}
	}

	return 1;
}

void main()
{
	char s[1000], r[1000];
	int i, j, f, t;
	long n;
	
	//freopen( "a.in", "r", stdin );	
	
	while ( scanf( "%s %d %d", s, &f, &t ) != EOF )
	{
		i = 0;

		while( i < strlen( s ) - 1 && s[i] == '0' )
		{
			++i;
		}

		j = 0;

		while ( i < strlen( s ) )
		{
			r[j++] = s[i++];
		}

		r[j] = 0;

		strcpy( s, r );

		to_decimal( s, f, n );

		to_base_b( n, t, s );

		if ( strlen( s ) > 7 )
		{
			printf( "  ERROR\n" );
		}
		else
		{
			printf( "%7s\n", s );
		}
	}		
}