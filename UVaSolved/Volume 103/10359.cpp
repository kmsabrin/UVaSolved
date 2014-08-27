#include <stdio.h>
#include <string.h>

#define MAXDIGIT 200

char result[251][200];

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

int main()
{
	char a[MAXDIGIT], b[MAXDIGIT], c[MAXDIGIT];
	int i;

	strcpy( result[0], "1" );
	strcpy( result[1], "1" );
	strcpy( result[2], "3" );

	
	for ( i = 3; i <= 250; ++i )
	{
		strcpy( a, result[i - 1] );
		strcpy( b, result[i - 2] );

		add( a, b, c );

		strcpy( a, c );

		add( a, b, c );

		strcpy( result[i], c );
	}
	

	while ( scanf( "%d", &i ) != EOF )
	{
		puts( result[i] );
	}
	
	return 0;
}