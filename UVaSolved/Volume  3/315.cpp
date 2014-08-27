#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNODES 100

int dfn[MAXNODES + 10];
int parent[MAXNODES + 10];
int L[MAXNODES + 10];
char adj[MAXNODES + 10][MAXNODES + 10];
char cPoint[MAXNODES + 10];
int num;
int nNodes;

int min( int a, int b )
{
	if ( a < b )
	{
		return a;
	}

	return b;
}

void articulationPoint( int u, int v )
{
	dfn[u] = num;
	L[u] = num;
	num = num + 1;

	for ( int i = 1; i <= nNodes; ++i )
	{
		if ( adj[u][i] )
		{
			if ( !dfn[i] )
			{
				parent[i] = u;

				articulationPoint( i, u );

				L[u] = min( L[u], L[i] );
			}
			else if ( i != v )
			{
				L[u] = min( L[u], dfn[i] );
			}
		}
	}
}

void main()
{
	int s, d;
	int i, j;
	char str[1000];
	char *p;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%d\n", &nNodes );

		if ( !nNodes )
		{
			break;
		}

		memset( adj, 0, sizeof( adj ) );

		while ( 1 )
		{
			gets( str );

			p = strtok( str, " " );

			s =  atoi( p );

			if ( !s )
			{
				break;
			}

			while ( p = strtok( NULL, " " ) )
			{
				d = atoi( p );

				adj[s][d] = adj[d][s] = 1;
			}
		}
		
		memset( dfn, 0, sizeof( dfn ) );

		for ( i = 1; i <= nNodes; ++i )
		{
			if ( !dfn[i] )
			{				
				num = 1;		
				parent[i] = 0;
				articulationPoint( i, 0 );
			}
		}

		memset( cPoint, 0, sizeof( cPoint ) );	

		for ( i = 1; i <= nNodes; ++i )
		{						
			j = parent[i];

			if ( L[i] >= dfn[j] && parent[j] > 0 )
			{									
				cPoint[j] = 1;				
			}			
			else if ( parent[j] < 1 )
			{
				++cPoint[j];
			}
		}

		for ( i = 1, j = 0; i <= nNodes; ++i )
		{
			if ( parent[i] > 0 && cPoint[i] )
			{
				++j;
			}
			else if ( parent[i] < 1 && cPoint[i] > 1 )
			{
				++j;
			}
		}


		printf( "%d\n", j );
	}
}
