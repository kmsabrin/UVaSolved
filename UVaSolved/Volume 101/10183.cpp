// FIBONACCI NUMBER

#include <stdio.h>
#include <string.h>

#define MAXDIGIT 110

char fibo[510][110];

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
	int i;
	
	if ( strlen( a ) > strlen( b ) )
	{
		return 1;
	}
	else if( strlen( a ) < strlen( b ) )
	{
		return -1;
	}
	else
	{
		for ( i = 0; i < strlen( a ); ++i )
		{
			if ( a[i] > b[i] )
			{
				return 1;
			}
			else if ( a[i] < b[i] )
			{
				return -1;
			}
		}
	}
	
	return 0;
}

int main()
{
	int i, j;
	char a[110], b[110];
	
	strcpy( fibo[1], "1" );
	strcpy( fibo[2], "2" );
	
	for ( i = 3; i < 505; ++i )
	{
		add( fibo[i - 2], fibo[i - 1], fibo[i] );
	}
	
	while ( scanf( "%s %s", a, b ) && !( a[0] == '0' && b[0] == '0' ) )
	{
		
		i = 1;
		
		while ( larger( a, fibo[i] ) == 1 )
		{
			++i;
		}
		
		j = 0;
		
		while ( larger( b, fibo[i] ) != -1 )
		{
			++j;
			++i;
		}
		
		printf( "%d\n", j );
		
		
	}
	
	return 0;
}