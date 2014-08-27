#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char a[30][30];

char visited[30];

char used[30];

int nAcorn, nTree;

void bfs( int s )
{
	queue <int> q;

	int acorn;

	q.push( s );

	acorn = 1;

	while ( !q.empty() )
	{
		s = q.front();

		q.pop();

		visited[s] = 1;
		
		for ( int i = 0; i < 26; ++i )
		{
			if ( a[s][i] && !visited[i] )
			{
				visited[i] = 1;

				q.push( i );

				acorn = 0;
			}
		}
	}

	if ( acorn )
	{
		++nAcorn;
	}
	else
	{
		++nTree;
	}
}

void main()
{
	int s, t, i, T;

	char str[100];

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &T );

	while ( T-- )
	{
		memset( a, 0, sizeof( a ) );

		memset( str, 0, sizeof( str ) );

		while ( 1 )
		{
			scanf( "%s", str );

			if ( str[0] == '*' )
			{
				break;
			}

			s = str[1] - 65;

			t = str[3] - 65;			

			a[s][t] = a[t][s] = 1;
		}

		scanf( "%s", str );

		memset( used, 0, sizeof( used ) );

		for ( i = 0; str[i]; i += 2 )
		{
			s = str[i] - 65;

			used[s] = 1;
		}

		memset( visited, 0, sizeof( visited ) );

		nTree = nAcorn = 0;

		for ( i = 0; i < 26; ++i )
		{
			if ( used[i] && !visited[i] )
			{		
				bfs( i );
			}
		}

		printf( "There are %d tree(s) and %d acorn(s).\n", nTree, nAcorn );
	}
}