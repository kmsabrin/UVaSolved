/**
*   //////////////////
*   // MAXIMUM FLOW //
*   //////////////////
**/

/***************
* Maximum flow * (Ford-Fulkerson on an adjacency matrix)
****************
* Takes a weighted directed graph of edge capacities as an adjacency 
* matrix 'cap' and returns the maximum flow from s to t.
*
* PARAMETERS:
*      - cap (global): adjacency matrix where cap[u][v] is the capacity
*          of the edge u->v. cap[u][v] is 0 for non-existent edges.
*      - n: the number of vertices ([0, n-1] are considered as vertices).
*      - s: source vertex.
*      - t: sink.
* RETURNS:
*      - the flow
*      - fnet contains the flow network. Careful: both fnet[u][v] and
*          fnet[v][u] could be positive. Take the difference.
*      - prev contains the minimum cut. If prev[v] == -1, then v is not
*          reachable from s; otherwise, it is reachable.
**/

#include <stdio.h>
#include <string.h>

#define INF 0x7fffffff

// the maximum number of vertices

#define NN 100

// adjacency matrix (fill this up)

int cap[NN][NN];

// flow network

int fnet[NN][NN];

// BFS

int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
	int u, v;
	
    // init the flow network

    memset( fnet, 0, sizeof( fnet ) );
	
    int flow = 0;
	
    while( true )
    {
        // find an augmenting path

        memset( prev, -1, sizeof( prev ) );

        qf = qb = 0;

        prev[q[qb++] = s] = -2;

        while( qb > qf && prev[t] == -1 )
		{
            for( u = q[qf++], v = 0; v < n; v++ )
			{
                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
				{
                    prev[q[qb++] = v] = u;
				}
			}
		}
		
		// see if we're done

		if( prev[t] == -1 ) 
		{
			break;
		}
		
		// get the bottleneck capacity

		int bot = INF;

		for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
		{
			if ( cap[u][v] - fnet[u][v] + fnet[v][u] < bot )
			{
				bot = cap[u][v] - fnet[u][v] + fnet[v][u];
			}
		}
		
		// update the flow network

		for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
		{
			fnet[u][v] += bot;			
		}
		
		flow += bot;
    }
	
    return flow;
}

int main()
{	
	int i, j, k, l, n, m, s, t, c;

	//freopen( "a.in", "r", stdin );

	c = 0;
	
	while ( 1 )
	{		
		scanf( "%d", &n );

		if ( n == 0 )
		{ 
			break;
		}
		
		scanf( "%d %d %d", &s, &t, &m );

		memset( cap, 0, sizeof( cap ) );
		
		for ( i = 1; i <= m; ++i )
		{
			scanf( "%d %d %d", &j, &k, &l );
			
			cap[j - 1][k - 1] += l;

			cap[k - 1][j - 1] += l;
		}
		
		printf( "Network %d\n", ++c );

		printf( "The bandwidth is %d.\n\n", fordFulkerson( n, s - 1, t - 1 ) );
	}
    
    return 0;
}
