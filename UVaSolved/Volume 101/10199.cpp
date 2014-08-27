// ARTICULATION POINT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNODES 100

int nNodes, nEdges;
char adj[MAXNODES + 10][MAXNODES + 10];

int comp( const void *i, const void *j )
{
	return strcmp( (char *)i, (char *)j );
}

int dfn[MAXNODES + 10];
int parent[MAXNODES + 10];
int L[MAXNODES + 10];
char cPoint[MAXNODES + 10];
int num;

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
	
	for ( int i = 0; i < nNodes; ++i )
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
	char place[MAXNODES + 10][35], s1[35], s2[35];
	int i, j, x, y, tc = 0;
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &nNodes ) && nNodes )
	{
		for ( i = 0; i < nNodes; ++i )
		{
			scanf( "%s", place[i] );
		}
		
		qsort( place, nNodes, sizeof( place[0] ), comp );
		
		scanf( "%d", &nEdges );
		
		memset( adj, 0, sizeof( adj ) );
		
		for ( i = 0; i < nEdges; ++i )
		{
			scanf( "%s %s", s1, s2 );
			
			for ( j = 0; j < nNodes; ++j )
			{
				if ( !strcmp( place[j], s1 ) )
				{
					x = j;
				}
				
				if ( !strcmp( place[j], s2 ) )
				{
					y = j;
				}
			}
			
			adj[x][y] = adj[y][x] = 1;
		}
		
		memset( dfn, 0, sizeof( dfn ) );
		
		for ( i = 0; i < nNodes; ++i )
		{
			if ( !dfn[i] )
			{				
				num = 1;		
				parent[i] = -1;
				articulationPoint( i, -1 );				
			}
		}
		
		/*for ( i = 0; i < nNodes; ++i )
		{
		printf( "%d %d %d\n", i, dfn[i], L[i] );
	}*/
		
		memset( cPoint, 0, sizeof( cPoint ) );
		
		for ( i = 0; i < nNodes; ++i )
		{						
			j = parent[i];
			
			if ( L[i] >= dfn[j] && parent[j] > -1 )
			{									
				cPoint[j] = 1;				
			}			
			else if ( parent[j] < 0 )
			{
				++cPoint[j];
			}
		}
		
		for ( i = j = 0; i < nNodes; ++i )
		{
			if ( parent[i] > -1 && cPoint[i] )
			{
				++j;
			}
			else if ( parent[i] < 0 && cPoint[i] > 1 )
			{
				++j;
			}
		}
		
		if ( tc > 0 )
		{
			printf( "\n" );
		}
		
		printf( "City map #%d: %d camera(s) found\n", ++tc, j );
		
		for ( i = 0; i < nNodes; ++i )
		{
			if ( parent[i] > -1 && cPoint[i] )
			{
				printf( "%s\n", place[i] );	
			}
			else if ( parent[i] < 0 && cPoint[i] > 1 )
			{
				printf( "%s\n", place[i] );
			}
		}
		
	}
}