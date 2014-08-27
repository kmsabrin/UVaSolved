#include <math.h>
#include <stdio.h>

double PI = 2 * acos( 0.0 );

double convert( double a, double b, double c, char s[] )
{
	
	a = a + b / 60.0 + c / 3600.0;
	a = a * ( PI / 180.0 );

	if ( s[0] == 'S' || s[0] == 'W' )
		a = -a;

	return a;
}

double sphereDistance( double p_lat, double p_lon, double q_lat, double q_lon, double r )
{
	
	double dlon = q_lon - p_lon;
	double dlat = q_lat - p_lat;
	double a = pow( sin( dlat / 2 ), 2.0 ) + cos( p_lat ) * cos( q_lat ) * pow( sin( dlon / 2 ) , 2.0 );	
	double c = 2 * atan2( sqrt( a ), sqrt( 1 - a ) ) ;
	double d = r * c;

	return d;
}

int main()
{

	double a, b, c;
	double lat1, lon1, lat2, lon2;
	double dist;
	char str[2];
	int tc;

	//freopen( "in.in", "r", stdin );

	scanf( "%d", &tc );

	while ( tc-- )
	{

		scanf( "%lf %lf %lf %s", &a, &b, &c, str );
		lat1 = convert( a, b, c, str );

		scanf( "%lf %lf %lf %s", &a, &b, &c, str );
		lon1 = convert( a, b, c, str );

		scanf( "%lf %lf %lf %s", &a, &b, &c, str );
		lat2 = convert( a, b, c, str );

		scanf( "%lf %lf %lf %s", &a, &b, &c, str );
		lon2 = convert( a, b, c, str );

		dist = sphereDistance( lat1, lon1, lat2, lon2, 6371.01 );

		printf( "%.2lf\n", dist );
	}

	return 0;

}