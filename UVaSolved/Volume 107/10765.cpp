// ARTICULATION POINT FINDING CODE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNODES 10000

#define min(a,b) ((a) < (b)) ? a : b

int dfn[MAXNODES + 1]; // dfs tree number
int parent[MAXNODES + 1];
int L[MAXNODES + 1];
char cPoint[MAXNODES + 1];
int num;
int nNodes;
int nArticulationPoint;

struct 
{
	int list[11];
	int num;
}	adj[MAXNODES + 1];

struct d
{
	int a, b;
}	dummy[MAXNODES + 1];

int comp( const void *i, const void *j )
{
	struct d* p = (struct d*) i;
	struct d* q = (struct d*) j;

	if ( p->a != q->a )
	{
		return q->a - p->a;
	}
	else
	{
		return p->b - q->b;
	}
}

/*
int min( int a, int b )
{
	if ( a < b )
	{
		return a;
	}
	
	return b;
}*/

void articulationPoint( int u, int v )
{	
	dfn[u] = num;
	L[u] = num;
	num = num + 1;
	
	int i, j;

	for ( j = 0; j < adj[u].num; ++j )
	{
		i = adj[u].list[j];

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

void art()
{
	int i, j;

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
			
	for ( i = 0; i < nNodes; ++i )
	{						
		j = parent[i];
		
		if ( j > 0 && L[i] >= dfn[j] )
		{									
			++cPoint[j];				
		}
		else if ( j == 0 )
		{
			++cPoint[j];
		}
	}	
}

void main()
{
	int nTargets;

	int i, j, k;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d %d", &nNodes, &nTargets ) && ( nNodes || nTargets ) )
	{
		for ( i = 0; i < nNodes; ++i )
		{
			adj[i].num = 0 ;
			cPoint[i] = 1;
		}

		cPoint[0] = 0;

		while ( 1 )
		{
			scanf( "%d %d", &j, &k );

			if ( j == -1 && k == -1 )
			{
				break;
			}

			adj[j].list[adj[j].num++] = k;

			adj[k].list[adj[k].num++] = j;
		}

		art();

		for ( i = 0; i < nNodes; ++i )
		{
			dummy[i].a = cPoint[i];
			dummy[i].b = i;
		}

		qsort( dummy, nNodes, sizeof( dummy[0] ), comp );

		for ( i = 0; i < nTargets; ++i )
		{
			printf( "%d %d\n", dummy[i].b, dummy[i].a );
		}

		printf( "\n" );
	}
}