#include <stdio.h>
#include <string.h>

#define MAXDIGIT 10000

void add( char a[], char b[], char c[] ) // c = a + b
{
	char x[MAXDIGIT], y[MAXDIGIT], z[MAXDIGIT];
	int sum, carry;
	int i, j;

	memset( x, -1, sizeof( x ) );
	memset( y, -1, sizeof( y ) );
	memset( z, -1, sizeof( z ) );

	for ( i = strlen( a ) - 1, j = 0; i > -1; --i, ++j )
	{
		x[j] = a[i];
	}

	for ( i = strlen( b ) - 1, j = 0; i > -1; --i, ++j )
	{
		y[j] = b[i];
	}

	i = carry = 0;

	while ( 1 )
	{
		if ( x[i] == -1 && y[i] == -1 )
		{
			break;
		}

		sum = carry;

		if ( x[i] != -1 )
		{
			sum += x[i] - 48;
		}

		if ( y[i] != -1 )
		{
			sum += y[i] - 48;
		}

		z[i] = ( sum % 10 ) + 48;
		carry = sum / 10;

		++i;
	}

	if ( carry )
	{
		z[i] = carry + 48;
		++i;
	}

	for ( --i, j = 0; i > -1; --i, ++j )
	{
		c[j] = z[i];
	}

	c[j] = 0;
}

int divide( char a[], int v ) // result = a / v
{
	int i, s, d;

	for ( i = s = 0, d = 0; a[i]; ++i )
	{
		s = s * 10 + a[i] - 48;

		if ( d )
		{
			if ( s < v )
			{
				printf( "0" );
			}
			else
			{
				printf( "%d", s / v );

				s %= v;
			}
		}
		else
		{
			if ( s >= v )
			{
				printf( "%d", s / v );

				s %= v;
				
				d = 1;
			}
		}
	}

	if ( !d )
	{
		printf( "0" );
	}

	printf( "\n\n" );

	return 0;
}

int main()
{	
	int i, n, f, k = 1;

	char a[50], s[100];

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%d %d", &n, &f );

		if ( !n && !f )
		{
			break;		
		}

		s[0] = 0;

		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", a );

			add( a, s, s );			
		}

		printf( "Bill #%d costs %s: each friend should pay ", k++, s );

		divide( s, f );
	}

	return 0;
}

