#include<stdio.h>

int main()
{
	char p[10001];

	int a[10001], prime[2000];

	int i, j, k, x, y, f, n;

	for ( i = 0; i < 10001; ++i )
	{
		p[i] = 1;
	}

	for( i = 2; i * i < 10001; ++i )
	{
		if ( p[i] )
		{
			for ( j = i * i; j < 10001; j += i )
			{
				p[j] = 0;
			}
		}
	}

	prime[0] = 2;

	for ( k = 3, n = 1; k < 10001; k += 2 )
	{
		if ( p[k] )
		{
			prime[n++] = k;
		}
	}

	a[0] = 1;

	for( i = 1; i <= 10000; i++)
	{
		j = ( i * i ) + i + 41;

		f = 1;

		for ( k = 0; k < n && prime[k] * prime[k] <= j; ++k )
		{
			if ( j % prime[k] == 0 )
			{
				f = 0;
				break;
			}
		}

		if ( f )
		{			
			a[i] = a[i - 1] + 1;
		}
		else
		{
			a[i] = a[i - 1];
		}
	}

	while ( scanf( "%d %d", &x, &y) != EOF )
	{
		if ( x > 0 )
		{
			j = a[y] - a[x - 1];
		}
		else
		{
			j = a[y] - a[x] + 1;
		}

		printf( "%.2lf\n", ( ( (double)j / (double)( y - x + 1) ) * 100.00 ) + 0.000000001 );
	}

	return 0;
}

