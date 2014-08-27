#include <math.h>
#include <stdio.h>

#define INF 10e15
#define MAXNODES 100

int nodes;	// number of nodes
int parent[MAXNODES];
double weight[MAXNODES][MAXNODES];
double mst_len;

struct
{
	double x, y;
} point[MAXNODES];

void prim( int start )
{
	int i, v;
	double min;
	bool intree[MAXNODES];
	double distance[MAXNODES];

	for ( i = 0; i < nodes; ++i )
	{
		intree[i] = false;
		distance[i] = INF;
		parent[i] = -1;
	}

	distance[start] = 0;
	v = start;

	while ( intree[v] == false )
	{
		intree[v] = true;

		mst_len += distance[v];

		for ( i = 0; i < nodes; ++i )
		{
			if ( intree[i] == false && weight[v][i] < distance[i] )
			{
				distance[i] = weight[v][i];
				parent[i]=  v;
			}
		}

		v = 0;
		min = INF;

		for ( i = 1; i < nodes; ++i )
		{
			if ( intree[i] == false && distance[i] < min )
			{
				min = distance[i];
				v = i;
			}
		}
	}

}

double dist( int i, int j )
{
	return sqrt ( ( point[i].x - point[j].x ) * ( point[i].x - point[j].x ) + 
		          ( point[i].y - point[j].y ) * ( point[i].y - point[j].y ) );
}

int main()
{
	int i, j, tc;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &tc );
	
	while ( tc-- )
	{
		scanf( "%d", &nodes );

		for ( i = 0; i < nodes; ++i )
		{
			scanf( "%lf %lf", &point[i].x, &point[i].y );
		}

		for ( i = 0; i < nodes; ++i )
		{
			for ( j = 0; j < nodes; ++j )
			{
				weight[i][j] = weight[j][i] = dist( i, j );
			}
		}

		mst_len = 0;

		prim( 0 );
		
		printf( "%.2lf\n", mst_len );

		if ( tc )
		{
			printf( "\n" );
		}
	}

	return 0;
}




