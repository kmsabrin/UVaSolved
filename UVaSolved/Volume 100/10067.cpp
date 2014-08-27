#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

bool visited[10000]; // true if visited
bool forbidden[10000]; // true if forbidden
int length[10000];  // contain bfs tree length
int target;

void get_num( int s, int m, int &p, int &q )
{ 
	int r;

	if ( m == 1 )
	{
		r = s % 10;

		if ( r == 0 )
		{
			p = s + 1;
			q = s + 9;
		}
		else if ( r == 9 )
		{
			p = s - 1;
			q = s - 9;
		}
		else
		{
			p = s + 1;
			q = s - 1;
		}
	}
	else if ( m == 2 )
	{
		r = s / 10;
		r = r % 10;

		if ( r == 0 )
		{
			p = s + 10;
			q = s + 90;
		}
		else if ( r == 9 )
		{
			p = s - 10;
			q = s - 90;
		}
		else
		{
			p = s + 10;
			q = s - 10;
		}
	}
	else if ( m == 3 )
	{
		r = s / 100;
		r = r % 10;

		if ( r == 0 )
		{
			p = s + 100;
			q = s + 900;
		}
		else if ( r == 9 )
		{
			p = s - 100;
			q = s - 900;
		}
		else
		{
			p = s + 100;
			q = s - 100;
		}
	}
	else if ( m == 4 )
	{
		r = s / 1000;
		r = r % 10;

		if ( r == 0 )
		{
			p = s + 1000;
			q = s + 9000;
		}
		else if ( r == 9 )
		{
			p = s - 1000;
			q = s - 9000;
		}
		else
		{
			p = s + 1000;
			q = s - 1000;
		}
	}
}

void bfs( int u )
{
	int i, j, k, s;
	queue<int> q;

	visited[u] = true;
	length[u] = 0;
	q.push( u );

	while( q.empty() == false )	
	{
		s = q.front();
		q.pop();
		
		for ( i = 1; i <= 4; ++i )
		{			
			get_num( s, i, j, k );

			if ( visited[j] == false && forbidden[j] == false )
			{
				q.push( j );
				visited[j] = true;
				length[j] = length[s] + 1;								
			}

			if ( visited[k] == false && forbidden[k] == false )
			{
				q.push( k );
				visited[k] = true;
				length[k] = length[s] + 1;
			}
		}

		if ( length[target] != -1 )
		{
			break;
		}

	}
}

int convert_num( char str[] )
{
	return ( str[0] - 48 ) * 1000 + ( str[2] - 48 ) * 100 + ( str[4] - 48 ) * 10 + ( str[6] - 48 ); 
}

int main()
{
	int tc, i, j, n, s;
	char str[10];

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	
	scanf( "%d\n", &tc );

	while ( tc-- )
	{
		gets( str );		
		s = convert_num( str );

		gets( str );		
		target = convert_num( str );

		scanf( "%d\n", &n );

		memset( forbidden, false, sizeof( forbidden ) ); 

		for ( i = 0; i < n; ++i )
		{
			gets( str );
			j = convert_num( str );
			forbidden[j] = true;
		}

		memset( visited, false, sizeof( visited ) ); 
		memset( length, -1, sizeof( length ) ); 

		bfs( s );

		printf( "%d\n", length[target] );

		scanf( "\n" );
	}

	return 0;
}


