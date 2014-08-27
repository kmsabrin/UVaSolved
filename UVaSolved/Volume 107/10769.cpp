#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp( const void *i, const void *j )
{
	return *(int *)j - *(int *)i;
}

char str[100000];

void main()
{
	int i, j, k, l, h, n, m, f;

	int a[101], b[101];

	char *p;

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d\n", &h ) != EOF  )
	{	
		gets( str );

		n = 0;
		
		p = strtok( str, " " );
		
		a[n++] = atoi( p );
		
		while ( p = strtok( NULL, " " ) )
		{
			a[n++] = atoi( p );
		}

		
		gets( str );

		m = 0;
		
		p = strtok( str, " " );
		
		b[m++] = atoi( p );
		
		while ( p = strtok( NULL, " " ) )
		{
			b[m++] = atoi( p );
		}

		
		qsort( a, n, sizeof( a[0] ), comp );

		qsort( b, m, sizeof( b[0] ), comp );


		f = 0;

		for ( i = 0; !f && i < n; ++i )
		{
			if ( a[i] > h )
			{
				continue;;
			}

			for ( j = 0; !f && j < m; ++j )
			{
				if ( a[i] + b[j] > h )
				{
					continue;;
				}

				for ( k = i + 1; !f && k < n; ++k )
				{
					if ( a[i] + b[j] + a[k] > h )
					{
						continue;;
					}

					for ( l = j + 1; !f && l < m; ++l )
					{
						if ( a[i] + b[j] + a[k] + b[l] == h )
						{
							printf( "%d %d %d %d\n", a[i], b[j], a[k], b[l] );

							f = 1;

							break;
						}
					}
				}
			}
		}

		if ( !f )
		{
			printf( "no solution\n" );
		}
	}
}