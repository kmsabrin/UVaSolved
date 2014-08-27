#include <stdio.h>
#include <string.h>

#define SIZE 110

int n;
int indegree[SIZE];
int sorted[SIZE];

char item[SIZE][60];
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
	char r[60], s[60];
	int i, j, k, p;
	int m, t = 0;;

	//freopen( "a.in", "r", stdin );

	while( scanf( "%d", &n ) != EOF )
	{		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", item[i] );			
		}
		
		scanf( "%d", &m );
		
		memset( adj, 0, sizeof( adj ) );
		memset( indegree, 0, sizeof ( indegree ) );

		for ( i = 0; i < m; ++i )
		{
			scanf( "%s %s", r, s );
			
			for ( p = 0; p < n; ++p )
			{
				if ( !strcmp( item[p], r ) )
				{
					j = p;
				}
				
				if ( !strcmp( item[p], s ) )
				{
					k = p;
				}
			}
			
			if ( !adj[j][k] )
			{
				++indegree[k];
				adj[j][k] = 1;
			}
		}

		topo_sort();
				
		printf( "Case #%d: Dilbert should drink beverages in this order:", ++t );
		
		for ( i = 0; i < n; ++i )
		{
			printf( " %s", item[sorted[i]] );
		}

		printf( ".\n\n" );		
	}
}
	


