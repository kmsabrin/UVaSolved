#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODES 101
#define INF 0x7fffffff

int nodes;	// number of nodes
int a[MAXNODES][MAXNODES];

int dijkstra( int start )
{
	int i, j, v, min;
	bool intree[MAXNODES];
	int distance[MAXNODES];

	for ( i = 1; i <= nodes; ++i )
	{
		intree[i] = false;
		distance[i] = INF;		
	}

	distance[start] = 0;
	v = start;

	while ( intree[v] == false )
	{
		intree[v] = true;

		for ( i = 1; i <= nodes; ++i )
		{
			if ( a[v][i] != -1 && a[v][i] + distance[v] < distance[i] )
			{
				distance[i] = a[v][i] + distance[v];			
			}
		}

		v = 1;
		min = INF;

		for ( i = 2; i <= nodes; ++i )
		{
			if ( intree[i] == false && distance[i] < min )
			{
				min = distance[i];
				v = i;
			}
		}
	}

	for ( i = 1, j = -1; i <= nodes; ++i )
	{		
		if ( distance[i] > j )
		{
			j = distance[i];
		}
	}
	
	return j;
}

int main()
{
	int i, j, k;
	char str[10];

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &nodes );

	memset( a, -1, sizeof( a ) );

	for ( i = 1, k = 2; i < nodes; ++i )
	{
		for ( j = 1; j <= i; ++j )
		{
			scanf( "%s", str );
			if ( str[0] == 'x' )
			{
				a[k][j] = a[j][k] = -1;
			}
			else
			{
				a[k][j] = a[j][k] = atoi( str );
			}			
		}
		++k;		
	}

	printf( "%d\n", dijkstra( 1 ) );


	return 0;
}