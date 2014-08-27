#include <stdio.h>
#include <string.h>

#define MAX 250 * 250 + 1

int tmp[MAX];

int a[MAX], b[MAX];

int lis( int n )
{
	int i, j, k;
	int m;
	int len;

	len = 0;
	b[0] = 0;

	for ( i = 1; i < n; ++i )
	{
		if ( a[i] > a[b[len]] )
		{
			b[++len] = i;
			continue;
		}

		j = 0;
		k = len;

		while ( j < k )
		{
			m = ( j + k ) / 2;

			if ( a[b[m]] < a[i] )
			{
				j = m + 1;
			}
			else
			{
				k = m;
			}
		}
		
		b[j] = i;
	}

	return( len + 1 );	
}

void main()
{
	int tc, c = 0;
	int i, j, k;
	int p, q;
	
	scanf( "%d", &tc );	

	while ( tc-- )
	{
		scanf( "%d %d %d", &i, &p, &q );

		memset( tmp, 0, sizeof( tmp ) );
		
		for ( i = 1; i <= p + 1; ++i )
		{
			scanf( "%d", &j );
			tmp[j] = i;
		}

		for ( i = 1, k = 0; i <= q + 1; ++i )
		{
			scanf( "%d", &j );

			if ( tmp[j] )
			{
				a[k++] = tmp[j];
			}
		}
		
		printf( "Case %d: %d\n", ++c, lis( k ) );
	}
}