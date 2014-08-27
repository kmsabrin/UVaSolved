#include <stdio.h>
#include <stdlib.h>

int comp( const void *i, const void *j )
{
	return *(int *)i - *(int *)j ;
}

int n;
int a[10010];

int min( int a, int b )
{
	if ( a < b )
	{
		return a;
	}

	return b;
}

int max( int a, int b )
{
	if ( a < b )
	{
		return b;
	}

	return a;
}

int bsearch( int x )
{
	int i = 0; 
	int j = n - 1;
	int k;

	while ( i < j )
	{
		k = ( i + j ) / 2;

		if ( x > a[k] )
		{
			i = k + 1;
		}
		else
		{
			j = k;
		}
	}

	if ( x == a[i] )
	{
		return i;
	}

	return -1;
}

int main()
{
	int m, i, j, k, x, y, p, mini;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) != EOF )
	{
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &a[i] );
		}

		scanf( "%d", &m );

		qsort( a, n, sizeof( a[0] ), comp );

		mini = 0x7fffffff;

		for ( i = 0; i < n && a[i] <= m / 2; ++i )
		{
			j = m - a[i];

		//	printf( "%d %d\n", j, m - a[i] );

			p = bsearch( j );

			if ( p != -1 && p != i )
			{				
				k = abs ( a[i] - ( m - a[i] ) );

				if ( k < mini )
				{
					mini = k;
					x = min( a[i], m - a[i] );
					y = max( a[i], m - a[i] );
				}
			}
		}

		printf( "Peter should buy books whose prices are %d and %d.\n\n", x, y );
	}

	return 0;
}