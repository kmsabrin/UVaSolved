#include <stdio.h>
#include <string.h>

#define MAX 10000001
#define SOD_V 1000001
#define F2_V 5000001

//#define MAX 10001
//#define SOD_V 1001
//#define F2_V 5001

char f1[MAX + 100];
int f2[F2_V];
char f3[SOD_V];

int main()
{
	int i, t, n, a, b, c = 0;
	int tc;
	int s1, s2;
	int s, p, q;
	char str[20];

	memset( f1, -1, sizeof( f1 ) );

	s = 0;

	f2[0] = 0;

	for ( i = 1; i < MAX; ++i )
	{
		t = f3[i / 10] + ( i % 10 );

		if ( i < SOD_V )
		{
			f3[i] = t;
		}

		t += i;

		if ( f1[t] == -1 )
		{
			f1[t] = t - i;
		}

		if ( f1[i] == -1 )
		{
			++s;
		}

		if ( !( i & 1) )
		{
			f2[i >> 1] = s;
		}
	}

	scanf( "%d\n", &tc );

	while ( tc-- )
	{
		gets( str );

		for ( i = 0, n = 1; str[i]; ++i )
		{
			if ( str[i] == ' ' )
			{
				n = 2;
				break;
			}
		}

		printf( "Case %d: ", ++c );

		if ( n == 1 )
		{
			sscanf( str, "%d", &a );
			if ( f1[a] == -1 )
			{
				printf( "-1" );
			}
			else
			{
				printf( "%d", a - f1[a] );
			}
		}
		else
		{
			sscanf( str, "%d %d", &a, &b );

			p = a - 1;
			if ( p & 1 )
			{
				s1 = f2[( p - 1 ) >> 1];
				if ( f1[p] == -1 )
				{
					++s1;
				}
			}
			else
			{
				s1 = f2[p >> 1];
			}

			p = b;
			if ( p & 1 )
			{
				s2 = f2[( p - 1 ) >> 1];
				if ( f1[p] == -1 )
				{
					++s2;
				}
			}
			else
			{
				s2 = f2[p >> 1];
			}

			printf( "%d", s2 - s1 );

		}

		printf( "\n" );
	}

	return 0;
}