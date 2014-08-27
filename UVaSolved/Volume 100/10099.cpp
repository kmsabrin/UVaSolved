#include <stdio.h>

int n;

int w[401][401]; 

int max( int i, int j )
{
	if ( i > j )
		return i;
	return j;
}

int min( int i, int j )
{
	if ( i < j )
		return i;
	return j;
}

int takeInput()
{
	int m;
	scanf( "%d %d", &n, &m );

	if ( !n && !m )
		return 0;

	int i, j, k;
	for ( i = 1; i <= n; ++i )
		for ( j = 1; j <= n; ++j )
			w[i][j] = 0;
	
	int tmp;
	for ( i = 0; i < m; ++i )
	{		
		scanf( "%d %d %d", &j, &k, &tmp );
		w[j][k] = w[k][j] = tmp;
	}

	return 1;
}

void floydWarshall()
{
	for ( int k = 1; k <= n; ++k )
		for ( int i = 1; i <= n; ++i )
			for ( int j = 1; j <= n; ++j )
					w[i][j] = max( w[i][j], min( w[i][k], w[k][j] ) );

}

void result( int tc )
{
	int s, d, t;

	scanf( "%d %d %d", &s, &d, &t );
	
	if ( ( t % ( w[s][d] - 1 ) ) == 0 )
		t = t / ( w[s][d] - 1 );
	else
		t = t / ( w[s][d] - 1 ) + 1; 

	printf( "Scenario #%d\n", tc );
	printf( "Minimum Number of Trips = %d\n", t );
	printf( "\n" );
}

void main()
{
	int tcase = 0;

	//freopen ( "in.in", "r", stdin );

	while ( takeInput() )
	{
		floydWarshall();
		result( ++tcase );
	}
}




