
#include <stdio.h>

// FLOYD WARSHALL ALGORITHM FOR ALL PAIRS SHORTEST PATH

#define INF 0x7ffffff

#define MAXNODES 110

// number of nodes
int nNodes;

// (i,j) = INF if no edge, (i,j) = 0 if i = j, (i,j) = w if edge weigth is w
int weight[MAXNODES + 1][MAXNODES + 1]; 

void floyd_warshall()
{
	for ( int k = 1; k <= nNodes; ++k )
	{
		for ( int i = 1; i <= nNodes; ++i )
		{
			for ( int j = 1; j <= nNodes; ++j )
			{
				int l = weight[i][k] + weight[k][j];
				
				if ( l < weight[i][j] )
				{
					weight[i][j] = l;					
				}
			}
		}
	}
}	

void main()
{
	int T, t = 0, l, d, i, j, k, c, min, max;
	
	int spot[110];
	
	// freopen( "a.in", "r", stdin );

	//freopen( "a.out", "w", stdout );
	
	scanf( "%d", &T );
	
	while ( T-- )
	{
		scanf( "%d %d", &l, &d );
		
		for ( i = 1; i <= l; ++i )
		{
			for ( j = 1; j <= l; ++j )
			{
				if ( i == j )
				{
					weight[i][j] = 0;
				}
				else
				{
					weight[i][j] = INF;
				}
			}
		}
		
		for ( i = 0; i < d; ++i )
		{
			scanf( "%d %d %d", &j, &k, &c );
			
			if ( c < weight[j][k] )
			{
				weight[j][k] = weight[k][j] = c;
			}
		}
		
		nNodes = l;
		
		floyd_warshall();
		
		for ( c = 0, i = 6; i <= l; ++i )
		{						
			for ( j = 2; j <= 5; ++j )
			{
				if ( weight[j][i] != weight[j - 1][i] )
				{
					break;
				}
			}
			
			if ( j > 5 )
			{
				spot[c++] = i;
			}
		}
		
		printf( "Map %d: ", ++t );
				
		min = INF;
		
		for ( i = 0; i < c; ++i )
		{
			max = 0;
			
			k = spot[i];			
			
			for ( j = 1; j <= l; ++j )
			{
				if ( weight[j][k] > max )
				{
					max = weight[j][k];
				}
			}
			
			if ( max < min )
			{
				min = max;					
			}				
		}
				
		if ( min == INF )
		{
			printf( "-1\n" );
		}
		else
		{
			printf( "%d\n", min );
		}
		
	}
}
