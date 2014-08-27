#include <stdio.h>

#include <string.h>

#define M 1005

#define N 105

bool graph[M][N];

bool seen[N];

int matchL[M], matchR[N];

int n, m;

bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) 
	{
		if( graph[u][v] )
		{
			if( seen[v] ) 
			{
				continue;
			}
			
			seen[v] = true;

			if( matchR[v] < 0 || bpm( matchR[v] ) )
			{
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	}

    return false;
}

int main()
{	
	int st[25], cp[25];
	
	int c, p, cap, start;
	
	int i, j, k, l, r;
	
	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d %d", &c, &p ) )
	{	
		if ( c == 0 && p == 0 )
		{
			break;
		}
		
		m = p; 
		
		start = 0;
		
		for ( i = 0; i < c; ++i )
		{
			scanf( "%d", &cap );
			
			st[i] = start;
			
			cp[i] = cap;
			
			start += cap;
		}
		
		n = start;
		
		memset( graph, false, sizeof( graph ) );
		
		for ( i = 0; i < p; ++i )
		{
			scanf( "%d", &j );
			
			while ( j-- )
			{
				scanf( "%d", &k );
				
				for ( l = st[k - 1], r = 1; r <= cp[k - 1]; ++r, ++l )
				{
					graph[i][l] = true;
				}
			}
		}
		
		memset( matchL, -1, sizeof( matchL ) );
		
		memset( matchR, -1, sizeof( matchR ) );
		
		int cnt = 0;
		
		for ( i = 0; i < m; i++ )
		{
			memset( seen, false, sizeof( seen ) );
			
			if( bpm( i ) ) 
			{
				cnt++;
			}

			if ( cnt == n )
			{
				break;
			}
		}
		
		if ( cnt == n )
		{
			printf( "1\n" );

			i = 0;

			for ( j = 0; j < c; ++j )
			{
				k =  cp[j];
				
				printf( "%d", matchR[i] + 1 );

				++i;

				k--;

				while ( k-- )
				{
					printf( " %d", matchR[i] + 1 );

					++i;
				}

				printf( "\n" );
			}
		}
		else
		{
			printf( "0\n" );
		}
	}

    return 0;
}
