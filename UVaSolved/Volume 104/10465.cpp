#include <stdio.h>

int beer[10000 + 1];
int burger[10000 + 1];

int min( int a, int b )
{
	if ( a < b )
		return a;
	return b;
}

int max( int a, int b )
{
	if ( a > b )
		return a;
	return b;
}

int main()
{
	int n, m, T, i;
	int a, b, c, d;

	while ( scanf( "%d %d %d", &m, &n, &T ) != EOF )
	{
	
		if ( m > n )
		{	a = m, m = n, n = a; }

		for ( i = 0; i < m && i <= T; ++i )
		{
			beer[i] = i;
			burger[i] = 0;
		}

		for (	; i < n && i <= T; ++i )
		{
			burger[i] = burger[i - m] + 1;
			beer[i] = beer[i - m];			
		}
										
		for (	; i <= T; ++i )
		{
			a = burger[i - m] + 1;
			b = beer[i - m];
			c = burger[i - n] + 1;
			d = beer[i - n];

			if ( b < d )
			{
				burger[i] = a;
				beer[i] = b;
			}
			else if ( b == d )
			{
				burger[i] = max( a, c );
				beer[i] = b;
			}
			else
			{
				burger[i] = c;
				beer[i] = d;
			}
		}

		printf( "%d", burger[T] );

		if ( beer[T] )
			printf( " %d", beer[T] );

		printf( "\n" );
		
	}

	return 0;
}

