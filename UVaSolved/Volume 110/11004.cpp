#include <stdio.h>

struct 
{
	int a, b, c;
} road[3001];

struct
{
	int x, y;
} place[101];


int main()
{
	int i, j, t = 1;
	int r, s;
	int p, n, sum;

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &r ) && r )
	{

		for ( i = 0; i < r; ++i )
		{
			scanf( "%d %d %d", &road[i].a, &road[i].b, &road[i].c );
		}

		scanf( "%d", &s );

		for ( i = 0; i < s; ++i )
		{
			scanf( "%d %d", &place[i].x, &place[i].y );
		}

		for ( i = sum = 0; i < s; ++i ) 
		{
			p = n = 0;

			for ( j = 0; j < r; ++j )
			{
				if ( ( road[j].a * place[i].x + road[j].b * place[i].y + road[j].c ) < 0 )
				{
					++n;
				}
				else
				{
					++p;
				}
			}
			sum += ( p * ( p - 1 ) ) / 2 + ( n * ( n - 1 ) ) / 2;
		}

		printf( "Roadmap %d:\n", t++ );
		printf( "Negative Builders Ltd. will build %d New Roads.\n", sum );
	}

	return 0;
}


