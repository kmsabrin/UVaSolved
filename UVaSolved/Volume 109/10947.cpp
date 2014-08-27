#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 111

struct 
{
	int x, y, r;
} island[MAX];

int K, M;

bool visited[MAX]; 
bool a[MAX][MAX];  
int n;			  

void bfs()
{
	int i, s;
	queue<int> q;

	visited[0] = true;
	q.push( 0 );

	while ( q.empty() == false ) 
	{
		s =  q.front();
		q.pop();

		for ( i = 0; i <= n; ++i )
		{
			if ( a[s][i] == true && visited[i] == false )
			{
				visited[i] = true;
				q.push( i );
			}
		}

		if ( visited[1] == true )
		{
			break;
		}
	}
}

bool reachable( int i, int j )
{
	int a, b, c, d;

	if ( i == j )
	{
		return false;
	}

	c = K * M;
	d = island[i].r + island[j].r;
	b = c * c + 2 * c * d + d * d;
	a = ( island[i].x - island[j].x ) * ( island[i].x - island[j].x ) + 
		( island[i].y - island[j].y ) * ( island[i].y - island[j].y ) ;

	if ( b >= a )
	{
		return true;
	}

	return false;
}

int main()
{
	int i, j, k;

	//freopen( "a.in", "r", stdin );

	while( scanf( "%d %d", &K, &M ) != EOF )
	{				

		scanf( "%d %d %d", &island[0].x, &island[0].y, &island[0].r );
		scanf( "%d %d %d", &island[1].x, &island[1].y, &island[1].r );

		scanf( "%d", &k );		
		for ( i = 2, j = 0; j < k; ++j, ++i )
		{
			scanf( "%d %d %d", &island[i].x, &island[i].y, &island[i].r );
		}
		n = i;

		memset( a, 0, sizeof( a ) );
		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < n; ++j )
			{				
				a[i][j] = reachable( i, j );						
			}		
		}

		memset( visited, false, sizeof( visited ) );
		bfs();
		
		if ( visited[1] == true )
		{
			printf( "Larry and Ryan will escape!\n");
		}
		else
		{
			printf( "Larry and Ryan will be eaten to death.\n" );
		}

	}

	return 0;
}
