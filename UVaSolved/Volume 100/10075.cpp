#include <math.h>
#include <stdio.h>
#include <string.h>

double PI = 2 * acos( 0.0 );

int n, q, i1, i2;

int w[101][101];

struct
{
	double lat, lon;
	char name[41];
} cities[101];

double radian( double degree )
{
	return degree * ( PI / 180.0 );
}

int round( double f )
{
	return (int)( f + 0.5 ); 
}

int sphereDistance( double p_lat, double p_lon, double q_lat, double q_lon, double r )
{
	p_lat = radian( p_lat );
	p_lon = radian( p_lon );
	q_lat = radian( q_lat );
	q_lon = radian( q_lon );

	double dlon = q_lon - p_lon;
	double dlat = q_lat - p_lat;
	double a = pow( sin( dlat / 2 ), 2.0 ) + cos( p_lat ) * cos( q_lat ) * pow( sin( dlon / 2 ) , 2.0 );	
	double c = 2 * atan2( sqrt( a ), sqrt( 1 - a ) ) ;
	double d = r * c;

	return round( d );

}

int findIndex( char a[], char b[] )
{
	for ( int i = 0; i < n; ++i )
	{
		if ( !strcmp( cities[i].name, a ) )
			i1 = i;
		if ( !strcmp( cities[i].name, b ) )
			i2 = i;
	}

	return 0;
}

int min( int i, int j )
{
	if ( i < j )
		return i;
	return j;
}

int max( int i, int j )
{
	if ( i > j )
		return i;
	return j;
}

int floydWarshall()
{
	for ( int k = 0; k < n; ++k )
			for ( int i = 0; i < n; ++i )
				for ( int j = 0; j < n; ++j )
					w[i][j] = min( w[i][j], w[i][k] + w[k][j] );
	return 0;
}

int showTable()
{
	for ( int i = 0; i < n; ++i )
	{
		for ( int j = 0; j < n; ++j )
			printf( "%10d", w[i][j] );
		printf( "\n" );
	}

	return 0;
}

int takeInput()
{
	int i, j;
	char a[31], b[31];
	int m;

	
	scanf( "%d %d %d", &n, &m, &q );

	if ( !n && !m && !q )		
		return 0;
	
		
	for ( i = 0; i < n; ++i )
		scanf( "%s %lf %lf", &cities[i].name, &cities[i].lat, &cities[i].lon );

	for ( i = 0; i < n; ++i )
		for ( j = 0; j < n ; ++j )
			w[i][j] = 11111111;

	for ( i = 0; i < m; ++i )
	{
		scanf( "%s %s", a, b );
		findIndex( a, b );
		w[i1][i2] = sphereDistance( cities[i1].lat, cities[i1].lon,
											    cities[i2].lat, cities[i2].lon, 6378 );
	}
				
	floydWarshall();
	//showTable();

	return 1;
}

int takeQuery( int tc )
{
	char a[101], b[101];
	int i, m;

	m = q;

	printf( "Case #%d\n", tc );

	for ( i = 0; i < m; ++i )
	{
		scanf( "%s %s", a, b );

		findIndex( a, b );

		if ( w[i1][i2] == 11111111 )
			printf( "no route exists" );
		else
			printf( "%d km", w[i1][i2] ); 

		printf( "\n" );
	}

	return 0;
}

int main()
{
	
	int flg = 0;
	int tc = 0;
	//freopen( "in.in", "r", stdin );

	while ( takeInput() )
	{
		if ( flg )
			printf( "\n" );
		flg = 1;

		takeQuery( ++tc );
	}

	return 0;
}
