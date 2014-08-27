#include <stdio.h>
#include <string.h>

#define MAXNODES 100 + 1

char a[MAXNODES][MAXNODES];
char used[MAXNODES];
char d[MAXNODES];
int cnt;
int nodes;
int maxlen;
int minnode;

void dfs( int s )
{
	for ( int i = 1; i <= nodes; ++i )
	{
		if ( a[s][i] && !used[i] )
		{
			++cnt;

			if ( d[i] >= cnt )
			{
				--cnt;
				continue;
			}

			d[i] = cnt;

			used[i] = 1;

			dfs( i );

			--cnt;
			used[i] = 0;			
		}
	}
	
	if ( cnt == maxlen && s < minnode )
	{
		minnode = s;		
	}
	else if ( cnt > maxlen )
	{
		maxlen = cnt;
		minnode = s;
	}
}

void main()
{
	int j, k, sr;
	int c = 0;

	while ( 1 )
	{		
		scanf( "%d", &nodes );
		
		if ( !nodes )
		{
			break;
		}
		
		scanf( "%d", &sr );
		
		memset( a, 0, sizeof( a ) );
		
		while ( 1 )
		{
			scanf( "%d %d", &j, &k );
			
			if ( !j && !k )
			{
				break;
			}
			
			a[j][k] = 1;
		}
		
		maxlen = -1;
		minnode = 101;
		cnt = 0;
		memset( used, 0, sizeof( used ) );
		memset( d, 0, sizeof( d ) );
		
		dfs( sr );

		printf( "Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++c, sr, maxlen, minnode );  
	}
}
