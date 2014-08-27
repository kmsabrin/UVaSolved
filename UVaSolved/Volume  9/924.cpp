// THE BFS ALGORITHM

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAXNODES 2501

char a[MAXNODES + 10][MAXNODES + 10];  // adjancency matrix array, 1 if edge exits

char visited[MAXNODES + 10]; // 1 if already visited

int length[MAXNODES + 10];	// contains the bfs tree length from source to nodes

int nNodes;  // number of nodes

void bfs( int s )
{
	int day, max, i, r;

	int flg[1000];

	memset( flg, 0, sizeof( flg ) );

	queue <int> q;

	memset( visited, 0, sizeof( visited ) );

	memset( length, -1, sizeof( length ) );

	visited[s] = 1;

	length[s] = 0;

	q.push( s );

	r = s;

	while ( !q.empty() )
	{
		s = q.front();
		q.pop();

		for ( i = 0; i < nNodes; ++i )
		{
			if ( a[s][i] && !visited[i] )
			{
				visited[i] = 1;
				
				length[i] = length[s] + 1;

				q.push( i );
			}
		}
	}

	for ( i = max = 0; i < nNodes; ++i )
	{
		if ( i == r || length[i] == -1 )
		{
			continue;
		}

		++flg[length[i]];

		if ( flg[length[i]] > max )
		{
			max = flg[length[i]];
			day = length[i];
		}
		else if ( flg[length[i]] == max )
		{
			if ( length[i] < day )
			{
				day = length[i];
			}
		}
	}

	if ( max == 0 )
	{
		printf( "0\n" );
	}
	else
	{
		printf( "%d %d\n", max, day );
	}
}

void main()
{
	int i, j, k, m, t;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &nNodes ) != EOF )
	{
		for ( i = 0; i < nNodes; ++i )
		{
			scanf( "%d", &m );

			for ( j= 0; j < m; ++j )
			{
				scanf( "%d", &k );

				a[i][k] = 1;		
			}
		}

		scanf( "%d", &t );
	
		while ( t-- )
		{
			scanf( "%d", &k );
			
			bfs( k );
		}
	}
}
