#include <stdio.h>
#include <string.h>

#define SIZE 110

int n;
int indegree[SIZE];
int sorted[SIZE];

int item[SIZE];
char adj[SIZE][SIZE];

void topo_sort()
{
	int i, j, k, f;
	int a[SIZE];

	memset( a, 0, sizeof( a ) );

	for ( i = 0; i < n; ++i )
	{
		if ( !indegree[i] )
		{
			a[i] = 1;
		}
	}

	j = 0;
	f = 1;

	while ( f )
	{			
		for ( i = f = 0; i < n; ++i )
		{
			if ( a[i] )
			{
				k = i;
				a[i] = 0;
				f = 1;
				break;
			}
		}
		
		sorted[j++] = k;

		for ( i = 0; i < n; ++i )
		{
			if ( adj[k][i] )
			{
				--indegree[i];

				if ( !indegree[i] )
				{
					a[i] = 1;
				}
			}
		}
	}
}

void main()
{	
	int i, j, k, m;

	//freopen( "a.in", "r", stdin );

	while( 1 )
	{		
		scanf( "%d %d", &n, &m );

		if ( n == 0 && m == 0 )
		{
			break;
		}
		
		memset( adj, 0, sizeof( adj ) );

		memset( indegree, 0, sizeof ( indegree ) );

		for ( i = 0; i < m; ++i )
		{
			scanf( "%d %d", &j, &k );
			
			--j; --k;

			if ( !adj[j][k] )
			{
				++indegree[k];
				adj[j][k] = 1;
			}
		}

		topo_sort();
								
		for ( i = 0; i < n; ++i )
		{
			printf( "%d ", sorted[i] + 1 );
		}

		printf( "\n" );		
	}
}
	


