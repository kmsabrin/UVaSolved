#include <stdio.h>
#include <stdlib.h>

int gcd( int a, int b )
{
	if ( b == 0 )
		return a;
	return gcd( b, a % b );
}

int main()
{
	int t, p11, p12, p21, p22, s11, s12, s21 ,s22, a, b, c, d;

	int p, j;

	scanf( "%d", &t );

	while ( t-- )
	{
	
		scanf( "%d %d %d %d", &s11, &s12, &p11, &p12 );
		scanf( "%d %d %d %d", &s21, &s22, &p21, &p22 );

		p = gcd( p11, p12 );
		p = gcd( p, p21 );
		p = gcd( p, p22 );

		a = s11 % p;
		b = s12 % p;
		c = s21 % p;
		d = s22 % p;

		if ( a > c )
		{
			j = a - c;
			d = ( d + j ) % p;
			
		}
		else
		{
			j = c - a;
			b = ( b + j ) % p;
		}


		if ( b == d )			
		{
			printf( "Yes\n" );
		}
		else
		{
			printf( "No\n" );
		}

	}

	return 0;
}

