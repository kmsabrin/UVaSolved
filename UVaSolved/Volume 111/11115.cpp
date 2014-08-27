#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXDIGIT 100

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
	char a[MAXDIGIT], b[MAXDIGIT], c[MAXDIGIT];

	int i, n, d;

	while ( scanf( "%s %s", a, b ) )
	{
		n = atoi( a );

		d = atoi( b );

		if ( n == 0 && d == 0 )
		{
			break;
		}

		b[0] = '1';
		b[1] = 0;
		
		for ( i = 1; i <= d; ++i )
		{		
			multiply( a, b, c );

			strcpy( b, c );
		}

		if ( d == 0 )
		{
			c[0] = '1';
		}

		puts( c );
		
		memset( a, 0, sizeof( a ) );

		memset( b, 0, sizeof( b ) );

		memset( c, 0, sizeof( c ) );

	}

	return 0;
}