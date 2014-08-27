#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;

#define INF 0xfffffff

#define NN 2505

char cap[NN][NN];

char fnet[NN][NN];

char used[NN];

char bank[NN];

struct alist
{
	vector <int> l;
}	adj[NN];


int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
	int u, v, j, k;
	
	memset( used, 0, sizeof( used ) );
	
    int flow = 0;
	
    while( true )
    {		
        memset( prev, -1, sizeof( prev ) );
		
        qf = qb = 0;
		
        prev[q[qb++] = s] = -2;
		
		k = 0;

        while( qb > qf && prev[t] == -1 )
		{
			u = q[qf++];
			
            for( j = 0; j < adj[u].l.size(); j++ )
			{			
				v = adj[u].l[j];				

				if ( used[v] )
				{
					continue;
				}

				if ( bank[v] )
				{
					++k;

					if ( k > 1 )
					{
						--k;
						continue;
					}
				}

                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
				{
                    prev[q[qb++] = v] = u;
				}
			}
		}
				
		if( prev[t] == -1 ) 
		{
			break;
		}
						
		int bot = INF;
		
		for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
		{
			if ( cap[u][v] - fnet[u][v] + fnet[v][u] < bot )
			{
				bot = cap[u][v] - fnet[u][v] + fnet[v][u];
			}
		}
					
		for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
		{
			fnet[u][v] += bot;			

			if ( v != t && v != s )
			{
				used[v] = 1;
			}			
		}
						
		flow += bot;
    }
	
    return flow;
}

void main()
{
	int s, a, b, src, snk, i, j, k, x, y, T;
	
	scanf( "%d", &T ) ;
	
	while ( T-- )
	{				
		scanf( "%d %d %d", &s, &a, &b );
		
		src = 0;
		
		snk = s * a + 1; 

		for ( i = 1; i <= s * a; ++i )
		{
			if ( i == 1 )
			{
				cap[i][i + 1] = cap[i][i + s] = 1;
				cap[i][snk] = 1;
			
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( snk );
			}
			else if ( i == s )
			{
				cap[i][i - 1] = cap[i][i + s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i - 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( snk );
			}
			else if ( i == ( ( a - 1 ) * s + 1 ) )
			{
				cap[i][i + 1] = cap[i][i - s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( snk );
			}
			else if ( i == s * a )
			{
				cap[i][i - 1] = cap[i][i - s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i - 1 );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( snk );
			}
			else if ( ( i - 1 ) % s == 0 )  
			{
				cap[i][i + 1] = cap[i][i + s] = cap[i][i - s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( snk );
			}			
			else if ( ( i % s ) == 0 )
			{
				cap[i][i - 1] = cap[i][i + s] = cap[i][i - s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i - 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( snk );
			}
			else if ( i > 1 && i < s ) 
			{
				cap[i][i + 1] = cap[i][i - 1] = cap[i][i + s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i - 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( snk );
			}
			else if ( i > ( ( a - 1 ) * s + 1 ) && i < s * a )
			{
				cap[i][i + 1] = cap[i][i - 1] = cap[i][i - s] = 1;
				cap[i][snk] = 1;
				
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i - 1 );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( snk );
			}
			else 
			{
				cap[i][i + 1] = cap[i][i - 1] = cap[i][i + s] = cap[i][i - s] = 1;
				
				adj[i].l.push_back( i + 1 );
				adj[i].l.push_back( i + s );
				adj[i].l.push_back( i - s );
				adj[i].l.push_back( i - 1 );
			}
		}
		
		memset( bank, 0, sizeof( bank ) );

		for ( i = 0; i < b; ++i )
		{
			scanf( "%d %d", &x, &y );
			
			k = ( x - 1 ) + s * ( y - 1 ) + 1;
			
			cap[src][k] = 1;

			bank[k] = 1;

			adj[src].l.push_back( k );		
		}		
		
		k = fordFulkerson ( snk + 1, src, snk );
		
		if ( k < b )
		{
			printf( "not possible\n" );
		}
		else
		{
			printf( "possible\n" );
		}

		for ( i = 0; i <= ( s * a ) + 1; ++i )
		{			
			for ( j = 0; j < adj[i].l.size(); ++j )
			{
				k = adj[i].l[j];

				cap[i][k] = cap[k][i] = fnet[i][k] = fnet[k][i] = 0;
			}
			
			adj[i].l.clear();
		}		
	}
}


