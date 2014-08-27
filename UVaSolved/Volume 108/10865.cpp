#include <stdio.h>

#define MAX 200000 + 1

int x[MAX], y[MAX];

int main()
{
	int i, s, o, n, bx, by;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) && n )
	{
		for ( i = 0; i < n; ++i )
			scanf( "%d %d", &x[i], &y[i] );

		bx = x[n / 2];
		by = y[n / 2];

		s = o = 0;
		for ( i = 0; i < n; ++i )
		{
			if ( x[i] == bx || y[i] == by )
				continue;
			if ( ( x[i] > bx && y[i] > by ) ||
			     ( x[i] < bx && y[i] < by ) )
				++s;
			else
				++o;
		}
		printf( "%d %d\n", s, o);
	}
	return 0;
}

