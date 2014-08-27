#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 45000

int fact[1000];
int p[5000];
char pr[MAX];

int comp( const void *i, const void *j )
{
	return *( int * )i - *( int * )j;
}

int getP()
{
	int i, j;
	memset( pr, 1, sizeof( pr ) );
	for ( i = 2; i * i < MAX; ++i )
		if ( pr[i] )
			for ( j = i * i; j < MAX; j += i )
				pr[j] = 0;

	j = 0;
	for ( i = 2; i < MAX; ++i )
		if ( pr[i] )
			p[j++] = i;
	return 0;
}

int factorize( int n )
{
	int i, j, k, e, s, ms, ss, pre, c, tc;

	e = 1;  tc = 0;
	fact[0] = 1;

	for ( i = 0; p[i] * p[i] <= n; ++i )
	{
		c = 0;
		while ( n % p[i] == 0  )
		{
			if ( c )
				ms = pre;
			else
				ms = 0;

			ss = pre = e;
			for ( j = ms; j < e; ++j, ++tc )
				fact[ss++] = fact[j] * p[i];
			e = ss;
			++c;
			n /= p[i];
		}
	}

	k = tc;
	if ( n != 1 )
	{
		for ( i = 0; i <= tc; ++i )
			fact[++k] = fact[i] * n;
	}


	qsort( fact, k + 1, sizeof( int ), comp );
	return k + 1;
}

int main()
{
	int t, c, r, i, j, cn = 0;
	getP();
	scanf( "%d", &t );

	while ( t-- )
	{
		scanf( "%d %d", &c, &r );
		c -= r;

		if ( !c )
			printf( "Case #%d: 0", ++cn );
		else
		{
			printf( "Case #%d:", ++cn );
			j = factorize( c );
			for( i = 0; i < j; ++i )
				if ( fact[i] > r )
					printf( " %d", fact[i] );
		}
		printf( "\n" );
	}
	return 0;
}




