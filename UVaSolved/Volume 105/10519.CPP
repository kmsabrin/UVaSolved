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

int larger( char a[], char b[] )
{
	char c[MAXDIGIT];
	int i;

	if ( strlen( a ) > strlen( b ) )
	{
		return 0;
	}
	else if( strlen( a ) < strlen( b ) )
	{
		strcpy( c, a );
		strcpy( a, b );
		strcpy( b, c );
		return 1;
	}
	else
	{
		for ( i = 0; i < strlen( a ); ++i )
		{
			if ( a[i] > b[i] )
			{
				return 0;
			}
			else if ( a[i] < b[i] )
			{
				strcpy( c, a );
				strcpy( a, b );
				strcpy( b, c );
				return 1;
			}
		}
	}

	return 0;
}

void subtract( char a[], char b[], char c[] ) // c = a - b
{
	char x[MAXDIGIT], y[MAXDIGIT], z[MAXDIGIT];
	int difference, borrow;
	int i, j, k, f;

	if ( !strcmp( a, b ) )
	{
		c[0] = 48;
		c[1] = 0;
		return;
	}

	f = larger( a, b ); // if f is 1 answer is negative

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

	i = borrow = 0;

	while ( 1 )
	{
		if ( x[i] == -1 && y[i] == -1 )
		{
			break;
		}

		if ( y[i] != -1 )
		{
			j = x[i] - 48;
			k = y[i] - 48 + borrow;

			if ( j >= k )
			{
				difference = j - k;
				borrow = 0;
			}
			else
			{
				difference = j + 10 - k;
				borrow = 1;
			}
		}
		else
		{
			j = x[i] - 48;
			k = borrow;

			if ( j >= k )
			{
				difference = j - k;
				borrow = 0;
			}
			else
			{
				difference = j + 10 - k;
				borrow = 1;
			}
		}

		z[i] = difference + 48;
		++i;
	}

	for ( --i; z[i] == '0'; --i )
		;

	for ( j = 0; i > -1; --i, ++j )
	{
		c[j] = z[i];
	}

	c[j] = 0;
}

void multiply( char a[], char b[], char c[] ) // c = a * b
{
	int i, j, k;
	int m, n, t;
	int count, carry;
	char ch;

	for ( i = 0; i < MAXDIGIT; ++i )
	{
		c[i] = 48;
	}

	n = strlen( a ) - 1;
	m = strlen( b ) - 1;

	if (a[0] == '0' || b[0] == '0')
	{
		c[0] = 48; c[1] = 0;
		return;
	}

	count = carry = 0;

	for ( i = m; i >= 0; --i )
	{
		k = count;

		for ( j = n; j >= 0; --j )
		{
			t = ( a[j] - 48 ) * ( b[i] - 48 ) + ( c[k] - 48 ) + carry;

			c[k] = t % 10 + 48;

			if ( t > 9 )
			{
				carry = t / 10;
			}
			else
			{
				carry = 0;
			}

			++k;
		}

		while ( carry )
		{
			c[k] = carry % 10 + 48;
			carry /= 10;
			++k;
		}

		++count;
	}

	c[k] = 0;

	for ( i = k - 1, j = 0; j < k / 2; --i, ++j )
	{
		ch = c[i]; c[i] = c[j]; c[j] = ch;

	}
}

int main()
{
	/*
	char a[MAXDIGIT], b[MAXDIGIT], c[MAXDIGIT];

	while ( gets( a ) )
	{
		gets( b );

		//addition( a, b, c );
		//subtraction( a, b, c );
		product( a, b, c );

		puts( c );
	}
	*/

	char str1[MAXDIGIT], str2[MAXDIGIT], res[MAXDIGIT];
	char s1[2];

	s1[0] = 50; s1[1] = 0;

	while ( gets( str1 ) )
	{
		if ( str1[0] == '0' )
		{
			printf( "1\n" );
			continue;
		}

		strcpy( str2, str1 );
		multiply( str1, str2, res );
		strcpy( str1, res );


		subtract( str1, str2, res );
		strcpy( str1, res );

		add( str1, s1, res );

		puts( res );
	}

	return 0;
}