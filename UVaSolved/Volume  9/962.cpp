#include <stdio.h>
#include <stdlib.h>

int a[441591 + 1], b[1555];

int comp( const void *i, const void *j )
{
	return *(int *)i - *(int *)j;
}

void main()
{
	freopen( "a.out", "w", stdout );

	int i, j, k, t, l, u, f;

	for ( k = 0, i = 1; i <= 1000; ++i )
	{
		for ( j = i; j <= 1000; ++j )
		{
			t = ( i * i * i ) + ( j * j * j );

			if ( t > 1000100000 )
			{
				break;
			}
	
			a[k++] = t;
		}
	}

	qsort( a, k, sizeof( a[0] ), comp );
	
	i = t = 0;

	while ( i < k )
	{
		if ( a[i] == a[i + 1] )
		{			
			b[t++] = a[i];			

			j = i + 2;

			while ( j < k && a[j] == a[i] )
			{
				++j;
			}

			i = j;
		}
		else
		{
			++i;
		}
	}	

	b[t] = 0x7fffffff;

	while ( scanf( "%d %d", &l, &u ) != EOF )
	{		
		i = f = 0;

		while ( b[i] < l )
		{
			++i;
		}
		
		while ( b[i] <= l + u )
		{
			printf( "%d\n", b[i++] );

			f = 1;
		}

		if ( !f )
		{
			printf( "None\n" );
		}
	}
}


