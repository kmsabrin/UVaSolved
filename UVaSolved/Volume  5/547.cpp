#include <stdio.h>

struct 
{
	int len;
	int val;
} a[3001];

int sumOfDigits( int n )
{
	int m = 0;

	while ( n )
	{
		m += n % 10;
		n /= 10;
	}

	return m;
}

void sumOfFactors( int n )
{
	if ( n == 15 )
	{
		a[n].val = 15;
		a[n].len = 1;
		return;
	}

	if ( n == 1 )
	{
		a[n].val = 1;
		a[n].len = 1;
		return;
	}


	if ( a[n].val != -1 )	
		return;

	int m = 0;

	for ( int i = 1; i * i <= n; ++i )
	{
		if ( n % i == 0 )
		{
			m += sumOfDigits( i );
			if ( i * i != n )
				m += sumOfDigits( n / i );
		}
	}

	a[n].val = m;

	if ( a[m].len == -1 )
		sumOfFactors( m );

	a[n].len = a[m].len + 1;

	return;

}


int main()
{
	int i, m, n, max, s, tc = 1, p, q;

	for ( i = 0; i < 3001; ++i )
		a[i].val = a[i].len = -1;

	for ( i = 1; i < 3001; ++i )
		sumOfFactors( i );

	//for ( i = 2; i < 20; ++i )
	//	printf( "%d : val = %d,  len = %d\n", i, a[i].val, a[i].len );

	while ( scanf( "%d %d", &m, &n ) != EOF )
	{
		p = m, q = n;
	
		if ( m > n )
		{
			max = n;
			n = m;
			m = max;
		}

		
		max = 0;

		for ( i = m; i <= n; ++i )
		{
			if ( a[i].len > max )
			{
				max = a[i].len;
				s = i;
			}
		}

		printf( "Input%d: %d %d\n", tc, p, q );
		printf( "Output%d:", tc++ );
		
		while ( 1 )
		{
			printf( " %d", s );

			if ( s == 15 || s == 1 )
				break;

			s = a[s].val;			
		}

		printf( "\n" );
	}

	return 0;
}
