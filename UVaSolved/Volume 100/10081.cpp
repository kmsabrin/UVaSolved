#include <math.h>
#include <stdio.h>
#include <string.h>

void main()
{
	double a[10];
	double b[10];
	int i, j, k;
	double s;
	double r[10][101];
	int n;

	for ( i = 2; i <= 9; ++i )
	{
		for ( j = 0; j <= i; ++j )
		{
			a[j] = 1;
		}

		r[i][1] = i + 1;

		for ( j = 2; j <= 100; ++j )
		{
			b[0] = a[0] + a[1];
			b[i] = a[i] + a[i - 1];

			s = b[0] + b[i];

			for ( k = 1; k < i; ++k )
			{
				b[k] = a[k - 1] + a[k] + a[k + 1];
				s += b[k];
			}

			r[i][j] = s;

			memcpy( a, b, sizeof( a ) );
		}
	}

	while ( scanf( "%d %d", &k, &n ) != EOF )
	{
		if ( k < 2 || n < 2 )
		{
			printf( "%.5lf\n", 100.0 );
		}
		else
		{
			printf( "%.5lf\n", ( r[k][n] / pow( k + 1, n ) ) * 100 );
		}
	}
}