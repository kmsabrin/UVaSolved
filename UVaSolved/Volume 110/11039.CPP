#include <stdio.h>
#include <stdlib.h>

struct v
{
	int a, b;
}s[500010];

int comp( const void *i, const void *j )
{
	struct v *p = (struct v *)i;
	struct v *q = (struct v *)j;

	return p->b - q->b;
}

int main()
{
	int tc, i, j, count, f, n;

	//freopen ( "a.in" ,"r", stdin );

	scanf( "%d", &tc);

	while ( tc-- )
	{
		scanf( "%d", &n );

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &s[i].a );
			s[i].b = abs( s[i].a );
		}

		qsort( s, n, sizeof(s[0] ), comp );

		if ( s[0].a < 0 )
		{
			f = 1;
		}
		else
		{
			f =  0;
		}

		count = 0;

		for ( i = 0; i < n;  )
		{
			if ( f == 1 )
			{
				while ( i < n && s[i].a < 0 )
				{
					++i;
				}

				++count;

				f = 0;
			}
			else
			{
				while ( i < n && s[i].a > 0 )
				{
					++i;
				}

				++count;

				f = 1;
			}
		}

		printf( "%d\n", count );
	}

	return 0;
}
