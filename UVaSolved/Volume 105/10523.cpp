#include <stdio.h>
#include <string.h>

#define MAXDIGIT 180

char res[151][16][1000];

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
	char a[MAXDIGIT], b[MAXDIGIT], c[MAXDIGIT], d[MAXDIGIT], e[MAXDIGIT], r[MAXDIGIT];
	int i, j, N, A;

	for( j = 0; j <= 15; ++j )
	{
			strcpy( r, "0" );
			strcpy( a, "1" );
			sprintf( b, "%d", j );

			for ( i = 1; i <= 150; ++i )
			{
				multiply( a, b, c );

				strcpy( a, c );

				sprintf( d, "%d", i );

				multiply( c, d, e );

				add( r, e, r );
			
				strcpy( res[i][j], r );
			}
	}


	while ( scanf( "%d %d", &N, &A ) != EOF )
	{
		puts( res[N][A] );
	}

	return 0;
}