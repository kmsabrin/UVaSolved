#include <stdio.h>
#include <string.h>

#define INF 0x7FFFFFF0
#define MAXNODES 101

int nodes;

int w[MAXNODES][MAXNODES]; 

int p[MAXNODES][MAXNODES];

int flg;

int cnt;

void floyd_warshall()
{	
	int i, j, k;

	memset( p, -1, sizeof( p ) );	

	for ( k = 1, flg = 1; k <= nodes; ++k )
	{
		for ( i = 1; i <= nodes; ++i )
		{
			for ( j = 1; j <= nodes; ++j )
			{
				if ( i != k && k != j && w[i][k] + w[k][j] < w[i][j] )
				{
					flg = 0;
					return;
				}

				if ( i != k && k != j && w[i][k] + w[k][j] == w[i][j] )
				{					
					p[i][j] = 0;					
				}				
			}
		}
	}	

	for ( i = 1, cnt = 0; i <= nodes; ++i )
	{
		for ( j = 1; j <= nodes; ++j )
		{
			if ( i == j || p[i][j] == 0 )
			{
				++cnt;
			}
		}
	}
}	

int main()
{
	int i, j, k, tc, c = 0;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d", &nodes );

		memset( w, 0, sizeof( w ) );
		
		for ( i = 1; i < nodes; ++i )
		{
			for ( j = 1; j <= i; ++j )
			{
				scanf( "%d", &k );

				w[i + 1][j] = w[j][i + 1] = k;
			}
		}

		floyd_warshall();

		printf( "Case #%d:\n", ++c );

		if ( flg == 0 )
		{
			printf( "Need better measurements.\n" );
		}
		else
		{
			printf( "%d\n", ( ( nodes * nodes ) - cnt ) / 2 );
			for ( i = 1; i <= nodes; ++i )
			{
				for ( j = i + 1; j <= nodes; ++j )
				{
					if ( i !=j && p[i][j] == -1 )
					{
						printf( "%d %d %d\n", i, j, w[i][j] );
					}
				}
			}
		}

		printf( "\n" );
	}

	return 0;
}


