#include <math.h>
#include <stdio.h>
#include <string.h>

double PI = 2 * acos( 0.0 );
int n, i1, i2;

struct
{
	double lati, longi;
	char name[41];
} cities[101];

double radian( double degree )
{
	return degree * ( PI / 180.0 );
}

double sphereDistance( double p_lat, double p_lon, double q_lat, double q_lon, double r )
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
	return d;

}

int takeInput()
{
	int i = 0;
	char tmp[101];

	while ( 1 )
	{
		scanf( "%s", tmp );
	
		if ( !strcmp( tmp, "#" ) )	
			break;

		strcpy( cities[i].name, tmp );

		scanf( "%lf %lf", &cities[i].lati, &cities[i].longi );

		++i;
	}

	n = i;

	return 0;
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

int round( double f )
{
	return (int)( f + 0.5 ); 
}

int takeQuery()
{
	char a[101], b[101];

	while ( 1 )
	{
		scanf( "%s %s", a, b );

		if ( !strcmp( a, "#" ) && !strcmp( b, "#" )  )	
			return 0;

		i1 = i2 = -1;
		findIndex( a, b );

		printf( "%s - %s\n", a, b );

		if ( i1 == -1 || i2 == -1 )
			printf( "Unknown" );
		else
			printf( "%d km", round( sphereDistance( cities[i1].lati, cities[i1].longi, cities[i2].lati, cities[i2].longi, 6378 ) ) );

		printf( "\n" );
	}

	return 0;
}

int main()
{
	
	//freopen( "in.in", "r", stdin );

	takeInput();
	takeQuery();

	return 0;
}
